/*
 * Arduino.c
 *
 *  Created on: Jan 11, 2019
 *      Author: super-tails
 */

#include "subsystems/Arduino.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

// "Sending _"
// "_"

// "Sending 5"
// "6"

template< typename T >
T correctEndianness(T value) {
	unsigned char *data = reinterpret_cast< unsigned char* >(&value);
	
	std::reverse(data, data + sizeof(T));

	return *reinterpret_cast< T* >(data);
}

// TODO: Check endianness here too
std::pair< std::vector<SensorFrame>, bool > Arduino::readData() {
	std::vector<RxFrame> rawFrames = readRawData();

	if (rawFrames.size() == 0) {
		return {
			std::vector<SensorFrame>(),
			false
		};
	}

	std::vector<SensorFrame> result;

	for (auto rawFrame : rawFrames) {
		result.push_back({
			static_cast<double>(rawFrame.x),
			static_cast<double>(rawFrame.y),
			static_cast<double>(rawFrame.width),
			static_cast<double>(rawFrame.height)
		});
	}

	return {
		result,
		true
	};
}

// TODO: Check endianness
// RoboRio is likely big endian and Arduinos are little endian
std::vector<Arduino::RxFrame> Arduino::readRawData() {
	uint8_t b[4] = { 'o', 'w', 'o', 0 };
	m_i2c.WriteBulk(b, 3);

	uint8_t buf[7] = { 0 };
	m_i2c.ReadOnly(7, buf);

	std::vector<RxFrame> buffer;
	for (int i = 0; i < buf[0]; ++i) {
		uint16_t x = (static_cast<uint16_t>(buf[1 + i * 6]) << 8) | buf[2 + i * 6];
		uint16_t width = (static_cast<uint16_t>(buf[3 + i * 6]) << 8) | buf[4 + i * 6];
		uint8_t y = buf[5 + i * 6];
		uint8_t height = buf[6 + i * 6];
		buffer.push_back(RxFrame{ x, y, width, height });
	}

	frc::SmartDashboard::PutNumber("Balls found", buf[0]);

	return buffer;
}