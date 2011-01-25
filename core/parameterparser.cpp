/**
   @file parameterparser.cpp
   @brief Parse for sensor parameters

   <p>
   Copyright (C) 2009-2010 Nokia Corporation

   @author Joep van Gassel <joep.van.gassel@nokia.com>
   @author Ustun Ergenoglu <ext-ustun.ergenoglu@nokia.com>

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

#include <QVariant>
#include <QStringList>

#include "parameterparser.h"
#include "logging.h"

QMap<QString, QString> ParameterParser::getPropertyMap(const QString& id)
{
    QMap<QString, QString> propMap;

    int pos = id.indexOf(TYPE_SEPARATOR);
    if ( pos != -1 )
    {
        QString propertiesString = id.mid(pos + 1);
        QStringList properties = propertiesString.split(PROP_STRING_SEPARATOR);

        foreach (const QString& property, properties)
        {
            pos = property.indexOf(PROP_NAME_VALUE_SEPARATOR);
            if ( pos != -1 )
            {
                QString name  = property.left( pos );
                // TODO: convert into a variant containing integer, string, ...
                QString value = property.mid( pos + 1 );

                propMap[name] = value;
                //sensordLogD() << "Added property:" << name << " with value" << value;
            }
            else
            {
                sensordLogW() << "Ignoring property:" << property;
            }
        }
    }

    return propMap;
}

void ParameterParser::applyPropertyMap(QObject* object, const QMap<QString, QString> & propertyMap)
{
    Q_ASSERT( object );

    for(QMap<QString, QString>::const_iterator it = propertyMap.constBegin(); it != propertyMap.constEnd(); ++it)
    {
        bool result = object->setProperty(it.key().toAscii().data(), QVariant(it.value()));
        if ( !result )
        {
            //sensordLogW() << "Property" << key << "is not static.";
        }
    }
}