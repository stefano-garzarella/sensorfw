/**
   @file plugin.h
   @brief Base class for plugins

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Semi Malinen <semi.malinen@nokia.com
   @author Joep van Gassel <joep.van.gassel@nokia.com>
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

#ifndef PLUGIN_H
#define PLUGIN_H

#include <QtPlugin>
#include <QStringList>

class PluginBase
{
public:
    virtual ~PluginBase();
    virtual void Register(class Loader& l) = 0;
    virtual void Init(class Loader&) {}
    virtual QStringList Dependencies() { return QStringList(); }
};

// TODO: figure out the proper name to use for the I/F
Q_DECLARE_INTERFACE(PluginBase, "com.nokia.SensorService.Plugin/1.0");

class Plugin : public QObject, PluginBase
{
    Q_OBJECT
    Q_INTERFACES(PluginBase)

public:
    virtual ~Plugin();
};

#endif
