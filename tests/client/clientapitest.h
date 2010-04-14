/**
   @file clientapitest.h
   @brief Automatic tests for sensor client interfaces

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Timo Rongas <ext-timo.2.rongas@nokia.com>

   This file is part of Sensord.

   Sensord is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Sensord is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with Sensord.  If not, see <http://www.gnu.org/licenses/>.
   </p>
*/

#ifndef CLIENT_API_TEST_H
#define CLIENT_API_TEST_H

#include <QTest>


class ClientApiTest : public QObject
{
    Q_OBJECT;

private slots:
    // Setup tests
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();

    // Sensors
    void testAccelerometerSensor();
    void testOrientationSensor();
    void testRotationSensor();
    void testTapSensor();
    void testMagnetometerSensor();
    void testCompassSensor();
    void testALSSensor();
    void testProximitySensor();

    // Special cases
    void testCommonAdaptorPipeline();
    void testListenSessionInitiation();
};

#endif // CLIENT_API_TEST_H
