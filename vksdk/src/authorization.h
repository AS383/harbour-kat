/*
  Copyright (C) 2016 Petr Vytovtov
  Contact: Petr Vytovtov <osanwe@protonmail.ch>
  All rights reserved.

  This file is part of Kat.

  Kat is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Kat is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Kat.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QUrlQuery>

#include <QDebug>

class Authorization : public QObject
{
    Q_OBJECT

public:
    explicit Authorization(QObject *parent = 0);
    ~Authorization();

    Q_INVOKABLE QString buildAuthUrl();
    Q_INVOKABLE void tryToGetAccessToken(QString url);

signals:
    void authorized(QString accessToken, QString userId);
    void error(QString errorCode, QString errorMessage);
};

#endif // AUTHORIZATION_H
