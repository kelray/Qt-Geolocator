/*
 * Copyright 2018, 2019 Karim El-Rayes. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY HONG XU ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL HONG XU OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of Hong Xu.
 *
 *
 *
 * Purpose: Graphical geolocator using USB GPS and Qt framework.
 *
 * Author: Karim El-Rayes
 *
 */
#include "mainwindow.h"
#include <QApplication>
#include <QGeoCodingManager>
 #include <QGeoCoordinate>
#include <QNmeaPositionInfoSource>
#include <QGeoServiceProvider>
#include <QDebug>
#include <QSerialPort>
#include <QPushButton>
#include "QMapControl/QMapControl.h"
#include "QMapControl/LayerMapAdapter.h"
#include "QMapControl/MapAdapterOSM.h"

using namespace std;
using namespace qmapcontrol;

QGeoCoordinate* Coordinate;
QGeoPositionInfo* location;
QNmeaPositionInfoSource* GPSdevice;
QSerialPort* serial;
QGeoServiceProvider* ServiceProvider;
QMapControl* m_map_control;

double longitude = 0.0;
double latitude = 0.0;
double altitude = 0.0;
char RxData[128];
int i = 0;
//NMEA nmea;
std::vector<PointWorldCoord> points;

void MainWindow::UpdateLocation()
{

}
void MainWindow::ButtonCallback()
{
    qDebug() << "Latitude: " << GPSdevice->lastKnownPosition(true).coordinate().latitude();     //Parsing GPS data using QNmeaPositionInfoSource
    qDebug() << "Longitude: " << GPSdevice->lastKnownPosition(true).coordinate().longitude();
    qDebug() << "Time: " << GPSdevice->lastKnownPosition(true).timestamp().toString();//.currentDateTime().toString();

    latitude = GPSdevice->lastKnownPosition(true).coordinate().latitude();
    longitude = GPSdevice->lastKnownPosition(true).coordinate().longitude();
    points.emplace_back(longitude, latitude);
    m_map_control->setMapFocusPoint(points, true);
    //m_map_control->zoomIn();
    //m_map_control->setZoomMaximum(8);
    //qDebug() << GPSdevice->lastKnownPosition(true);
    
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(720, 720);
    w.setWindowTitle("GPS Viewer");
    //Push button
    QPushButton *Button = new QPushButton(&w);
    Button->setText("Read GPS");
    Button->setGeometry(540, 600, 100, 30);

   

    // Create a new QMapControl.
    m_map_control = new QMapControl(QSizeF(480.0, 640.0), &w);
    m_map_control->setGeometry(30, 30, 480, 640);


    // Create/add a layer with the default OSM map adapter.
    m_map_control->addLayer(std::make_shared<LayerMapAdapter>("Custom Layer", std::make_shared<MapAdapterOSM>()));

    serial = new QSerialPort(&w);
    serial->setPortName("COM8");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadOnly);

    //Coordinate = new QGeoCoordinate(longitude, latitude);
    GPSdevice = new QNmeaPositionInfoSource(QNmeaPositionInfoSource::RealTimeMode);
    GPSdevice->setDevice(serial);

    w.show();
    QObject::connect(Button, SIGNAL(clicked()), &w, SLOT(ButtonCallback()));
    GPSdevice->requestUpdate(500);

    return a.exec();
}
