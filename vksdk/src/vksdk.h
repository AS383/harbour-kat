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

#ifndef VKSDK_H
#define VKSDK_H

//#include <QList>
#include <QObject>
//#include <QString>
//#include <QStringList>
//#include <QVariant>
//#include <QVariantList>

#include "authorization.h"
#include "objects/user.h"
#include "requests/apirequest.h"
#include "requests/users.h"

//#include "friends.h"
//#include "likes.h"
//#include "longpoll.h"
//#include "messages.h"
//#include "newsfeed.h"
//#include "photos.h"
//#include "videos.h"
//#include "wall.h"
//#include "models/dialogslistmodel.h"
//#include "models/messagesmodel.h"
//#include "models/newsfeedmodel.h"
//#include "objects/audio.h"
//#include "objects/chat.h"
//#include "objects/dialog.h"
//#include "objects/document.h"
//#include "objects/group.h"
//#include "objects/news.h"
//#include "objects/photo.h"
//#include "objects/friend.h"
//#include "objects/video.h"

class VkSDK : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Authorization* auth READ auth CONSTANT)

    Q_PROPERTY(Users* users READ users CONSTANT)

//    Q_PROPERTY(User* selfProfile READ selfProfile CONSTANT)

//    Q_PROPERTY(Friends* friends READ friends CONSTANT)
//    Q_PROPERTY(Likes* likes READ likes CONSTANT)
//    Q_PROPERTY(LongPoll* longPoll READ longPoll CONSTANT)
//    Q_PROPERTY(Messages* messages READ messages CONSTANT)
//    Q_PROPERTY(Newsfeed* newsfeed READ newsfeed CONSTANT)
//    Q_PROPERTY(Photos* photos READ photos CONSTANT)
//    Q_PROPERTY(Videos* videos READ videos CONSTANT)
//    Q_PROPERTY(Wall* wall READ wall CONSTANT)

//    Q_PROPERTY(DialogsListModel* dialogsListModel READ dialogsListModel)
//    Q_PROPERTY(MessagesModel* messagesModel READ messagesModel)
//    Q_PROPERTY(NewsfeedModel* newsfeedModel READ newsfeedModel)

public:
    explicit VkSDK(QObject *parent = 0);
    ~VkSDK();

    Q_INVOKABLE void setAccessTocken(QString value);
    Q_INVOKABLE void setUserId(int value);

    Authorization *auth() const;

    Users* users() const;

//    User* selfProfile() const;

//    Friends* friends() const;
//    Likes *likes() const;
//    LongPoll* longPoll() const;
//    Messages* messages() const;
//    Newsfeed* newsfeed() const;
//    Photos* photos() const;
//    Videos* videos() const;
//    Wall* wall() const;

//    DialogsListModel* dialogsListModel() const;
//    MessagesModel* messagesModel() const;
//    NewsfeedModel* newsfeedModel() const;

signals:
    void gotProfile(User *user);
//    void gotSelfProfile();
    //    void gotFriends(QVariant friends);
//    void gotMessages(QVariant messages);
//    void gotUnreadCounter(int value);
//    void gotVideo(Video *video);
//    void gotWallpost(News *wallpost);
//    void newsfeedModelChanged();

public slots:
    void gotResponse(QJsonValue value, ApiRequest::TaskType type);

//    void gotDialogList(QList<Dialog*> dialogsList);
//    void gotFriendsList(QList<QObject*> friendsList);
//    void gotMessagesList(QList<QObject*> messagesList);
//    void gotMutualFriendsIds(QVariantList ids);
//    void gotNewsfeed(QList<News*> items, QList<User*> profiles, QList<Group *> groups, QString nextFrom);
//    void gotUnreadDialogsCounter(int value);
//    void gotUserProfile(User *user);
//    void gotUsersList(QList<QObject*> usersList);
//    void gotVideoObject(Video *video);
//    void gotWallpostObject(News *wallpost);

//    void gotChatsList(QList<QObject*> chatsList);

private:
    QString _accessToken;
    int _userId;

    ApiRequest *_api;
    Authorization *_auth;

    Users *_users;

    User* parseUserProfile(QJsonArray array);

//    User *_selfProfile;

//    Friends *_friends;
//    Likes *_likes;
//    LongPoll *_longPoll;
//    Messages *_messages;
//    Newsfeed *_newsfeed;
//    Photos *_photos;
//    Videos *_videos;
//    Wall *_wall;

//    DialogsListModel *_dialogsListModel;
//    MessagesModel *_messagesModel;
//    NewsfeedModel *_newsfeedModel;

//    QStringList _usersIds;
//    QStringList _chatsIds;
//    QStringList _chatUsersIds;
//    QList<QObject*> _dialogs;

//    QStringList _getIdsFromMessages(QList<QObject*> messages);
};

#endif // VKSDK_H