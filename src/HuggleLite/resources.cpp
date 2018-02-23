//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#include "resources.hpp"
#include <QFile>

using namespace HuggleLite;

QByteArray Resources::LoadResource(QString path)
{
    QByteArray result;
    QFile *vf = new QFile(":" + path);
    if (!vf->open(QIODevice::ReadOnly))
    {
        //this->SystemLog("Failed to get diff");
        delete vf;
        return result;
    } else
    {
        result = vf->readAll();
        vf->close();
        delete vf;
        return result;
    }
}
