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

#include "user.h"

User::User(QObject *parent) : QObject(parent)
{}

User *User::fromJsonObject(QJsonObject object)
{
    User *user = new User();

    // System
    if (object.contains("id")) user->setId(object.value("id").toInt());
    if (object.contains("deactivated")) user->setDeactivated(object.value("deactivated").toString());
    if (object.contains("blacklisted")) user->setBlacklisted(object.value("blacklisted").toInt());
    if (object.contains("blacklisted_by_me")) user->setBlacklistedByMe(object.value("blacklisted_by_me").toInt());
    if (object.contains("can_post")) user->setCanPost(object.value("can_post").toInt() == 1);
    if (object.contains("can_see_all_posts")) user->setCanSeeAllPosts(object.value("can_see_all_posts").toInt() == 1);
    if (object.contains("can_see_audio")) user->setCanSeeAudio(object.value("can_see_audio").toInt() == 1);
    if (object.contains("can_send_friend_request")) user->setCanSendFriendRequest(object.value("can_send_friend_request").toInt() == 1);
    if (object.contains("can_write_private_message")) user->setCanWritePrivateMessage(object.value("can_write_private_message").toInt() == 1);
    if (object.contains("screen_name")) user->setDomain(object.value("screen_name").toString());
    if (object.contains("exports")) qDebug() << object.value("exports"); // TODO
    if (object.contains("friend_status")) user->setFriendStatus(object.value("friend_status").toInt());
    if (object.contains("is_favorite")) user->setIsFavorite(object.value("is_favorite").toInt() == 1);
    if (object.contains("is_hidden_from_feed")) user->setIsHiddenFromFeed(object.value("is_hidden_from_feed").toInt() == 1);
    if (object.contains("photo_max_orig")) user->setPhotoMaxOrig(object.value("photo_max_orig").toString());
    if (object.contains("verified")) user->setVerified(object.value("verified").toInt() == 1);

//    // Basic Info
//    if (object.contains("first_name")) user->setFirstName(object.value("first_name").toString());
//    if (object.contains("nickname")) qDebug() << object.value("nickname").toString(); // TODO
//    if (object.contains("last_name")) user->setLastName(object.value("last_name").toString());
//    if (object.contains("maiden_name")) qDebug() << object.value("maiden_name").toString(); // TODO
//    if (object.contains("online")) user->setOnline(object.value("online").toInt());
//    if (object.contains("photo_50")) user->setPhoto50(object.value("photo_50").toString());
//    if (object.contains("photo_200")) user->setPhoto200(object.value("photo_200").toString());
//    if (object.contains("status")) user->setStatus(object.value("status").toString());
//    if (object.contains("last_seen")) {
//        QJsonObject lastSeen = object.value("last_seen").toObject();
//        if (lastSeen.contains("time")) qDebug() << lastSeen.value("time").toInt(); // TODO
//        if (lastSeen.contains("platform")) qDebug() << lastSeen.value("platform").toInt(); // TODO
//    }
//    if (object.contains("bdate")) user->setBdate(object.value("bdate").toString());
//    if (object.contains("relation")) user->setRelation(object.value("relation").toInt());
//    if (object.contains("relation_partner")) { // TODO
//        QJsonObject partner = object.value("relation_partner").toObject();
//        if (partner.contains("id")) user->setRelationPartnerId(partner.value("id").toInt());
//        if (partner.contains("first_name")) qDebug() << partner.value("first_name").toString(); // TODO
//        if (partner.contains("last_name")) qDebug() << partner.value("last_name").toString(); // TODO
//        user->setRelationPartnerName(partner.value("first_name").toString() + " " + partner.value("last_name").toString());
//    }
//    if (object.contains("occupation")) {
//        QJsonObject occupation = object.value("occupation").toObject();
//        if (occupation.contains("type")) qDebug() << occupation.value("type").toString(); // TODO
//        if (occupation.contains("id")) qDebug() << occupation.value("id").toInt(); // TODO
//        if (occupation.contains("name")) qDebug() << occupation.value("name").toString(); // TODO
//    }
//    // --------------
//    if (object.contains("sex")) user->setSex(object.value("sex").toInt());
//    if (object.contains("city")) {
//        QJsonObject city = object.value("city").toObject();
//        if (city.contains("id")) user->setCity_id(city.value("id").toInt());
//        if (city.contains("title")) user->setCity_title(city.value("title").toString());
//    }
//    if (object.contains("country")) {
//        QJsonObject country = object.value("country").toObject();
//        if (city.contains("id")) user->setCountry_id(country.value("id").toInt());
//        if (city.contains("title")) user->setCountry_title(country.value("title").toString());
//    }
//    if (object.contains("home_town")) qDebug() << object.value("home_town").toString(); // TODO
//    if (object.contains("contacts")) {
//        QJsonObject contacts = object.value("contacts").toObject();
//        if (contacts.contains("mobile_phone")) user->setContacts_mobilePhone(contacts.value("mobile_phone").toString());
//        if (contacts.contains("home_phone")) user->setContacts_homePhone(contacts.value("home_phone").toString());
//    }
//    if (object.contains("site")) qDebug() << object.value("site").toString(); // TODO
//    if (object.contains("relatives")) {
//        QJsonArray relatives = object.value("relatives").toArray();
//        foreach (QJsonObject person, relatives) {
//            if (person.contains("id")) qDebug() << person.value("id").toInt();
//            if (person.contains("name")) qDebug() << person.value("name").toString();
//            if (person.contains("type")) qDebug() << person.value("type").toString();
//        }
//    }

//    // Career
//    if (object.contains("career")) {
//        QJsonObject career = object.value("career").toObject();
//        if (career.contains("group_id")) user->setCareer_groupId(career.value("group_id").toInt());
//        if (career.contains("company")) user->setCareer_company(career.value("company").toString());
//        if (career.contains("country_id")) user->setCareer_countryId(career.value("country_id").toInt());
//        if (career.contains("city_id")) user->setCareer_cityId(career.value("city_id").toInt());
//        if (career.contains("city_name")) user->setCareer_cityName(career.value("city_name").toString());
//        if (career.contains("from")) user->setCareer_from(career.value("from").toInt());
//        if (career.contains("until")) user->setCareer_until(career.value("until").toInt());
//        if (career.contains("position")) user->setCareer_position(career.value("position").toString());
//    }
//    if (object.contains("education")) {
//        QJsonObject education = object.value("education").toObject();
//        if (education.contains("university")) user->setEducation_university(education.value("university").toInt());
//        if (education.contains("university_name")) user->setEducation_universityName(education.value("university_name").toString());
//        if (education.contains("faculty")) user->setEducation_faculty(education.value("faculty").toInt());
//        if (education.contains("faculty_name")) user->setEducation_facultyName(education.value("faculty_name").toString());
//        if (education.contains("graduation")) user->setEducation_graduation(education.value("graduation").toInt());
//    }
//    if (object.contains("universities")) {
//        QJsonArray universities = object.value("universities").toArray();
//        foreach (QJsonObject university, universities) {
//            if (university.contains("id")) qDebug() << university.value("id").toInt(); // TODO
//            if (university.contains("country")) qDebug() << university.value("country").toInt(); // TODO
//            if (university.contains("city")) qDebug() << university.value("city").toInt(); // TODO
//            if (university.contains("name")) qDebug() << university.value("name").toString(); // TODO
//            if (university.contains("faculty")) qDebug() << university.value("faculty").toInt(); // TODO
//            if (university.contains("faculty_name")) qDebug() << university.value("faculty_name").toString(); // TODO
//            if (university.contains("chair")) qDebug() << university.value("chair").toInt(); // TODO
//            if (university.contains("chair_name")) qDebug() << university.value("chair_name").toString(); // TODO
//            if (university.contains("graduation")) qDebug() << university.value("graduation").toString(); // TODO
//            if (university.contains("education_form")) qDebug() << university.value("education_form").toString(); // TODO
//            if (university.contains("education_status")) qDebug() << university.value("education_status").toString(); // TODO
//        }
//    }
//    if (object.contains("military")) {
//        QJsonObject military = object.value("military").toObject();
//        if (military.contains("unit")) qDebug() << military.value("unit").toString(); // TODO
//        if (military.contains("unit_id")) qDebug() << military.value("unit_id").toInt(); // TODO
//        if (military.contains("country_id")) qDebug() << military.value("country_id").toInt(); // TODO
//        if (military.contains("from")) qDebug() << military.value("from").toInt(); // TODO
//        if (military.contains("until")) qDebug() << military.value("until").toInt(); // TODO
//    }
//    if (object.contains("schools")) {
//        QJsonArray schools = object.value("schools").toArray();
//        foreach (QJsonObject school, schools) {
//            if (school.contains("id")) qDebug() << school.value("id").toInt(); // TODO
//            if (school.contains("country")) qDebug() << school.value("country").toInt(); // TODO
//            if (school.contains("city")) qDebug() << school.value("city").toInt(); // TODO
//            if (school.contains("name")) qDebug() << school.value("name").toString(); // TODO
//            if (school.contains("year_from")) qDebug() << school.value("year_from").toInt(); // TODO
//            if (school.contains("year_to")) qDebug() << school.value("year_to").toInt(); // TODO
//            if (school.contains("year_graduated")) qDebug() << school.value("year_graduated").toInt(); // TODO
//            if (school.contains("class")) qDebug() << school.value("class").toString(); // TODO
//            if (school.contains("speciality")) qDebug() << school.value("speciality").toString(); // TODO
//            if (school.contains("type")) qDebug() << school.value("type").toInt(); // TODO
//            if (school.contains("type_str")) qDebug() << school.value("type_str").toString(); // TODO
//        }
//    }

//    // Additional
//    if (object.contains("about")) user->setAbout(object.value("about").toString());
//    if (object.contains("personal")) {
//        QJsonObject personal = object.value("personal").toObject();
//        if (personal.contains("political")) qDebug() << personal.value("political").toInt(); // TODO
//        if (personal.contains("langs")) qDebug() << personal.value("langs").toArray(); // TODO
//        if (personal.contains("religion")) qDebug() << personal.value("religion").toString(); // TODO
//        if (personal.contains("inspired_by")) qDebug() << personal.value("inspired_by").toString(); // TODO
//        if (personal.contains("people_main")) qDebug() << personal.value("people_main").toInt(); // TODO
//        if (personal.contains("life_main")) qDebug() << personal.value("life_main").toInt(); // TODO
//        if (personal.contains("smoking")) qDebug() << personal.value("smoking").toInt(); // TODO
//        if (personal.contains("alcohol")) qDebug() << personal.value("alcohol").toInt(); // TODO
//    }
//    if (object.contains("activities")) user->setActivities(object.value("activities").toString());
//    if (object.contains("interests")) qDebug() << object.value("interests").toString(); // TODO
//    if (object.contains("quotes")) qDebug() << object.value("quotes").toString(); // TODO
//    if (object.contains("books")) user->setBooks(object.value("books").toString());
//    if (object.contains("movies")) qDebug() << object.value("movies").toString(); // TODO
//    if (object.contains("music")) qDebug() << object.value("music").toString(); // TODO
//    if (object.contains("games")) qDebug() << object.value("games").toString(); // TODO
//    if (object.contains("tv")) qDebug() << object.value("tv").toString(); // TODO

//    // Buttons
//    if (object.contains("connections")) qDebug() << object.value("connections"); // TODO
//    if (object.contains("counters")) {
//        QJsonObject counters = object.value("counters").toObject();
//        if (counters.contains("albums")) user->setAlbumsCounter(counters.value("albums").toInt());
//        if (counters.contains("videos")) user->setVideosCounter(counters.value("videos").toInt());
//        if (counters.contains("audios")) user->setAudiosCounter(counters.value("audios").toInt());
//        if (counters.contains("photos")) user->setPhotosCounter(counters.value("photos").toInt());
//        if (counters.contains("notes")) user->setNotesCounter(counters.value("notes").toInt());
//        if (counters.contains("friends")) user->setFriendsCounter(counters.value("friends").toInt());
//        if (counters.contains("groups")) user->setGroupsCounter(counters.value("groups").toInt());
//        if (counters.contains("online_friends")) user->setOnlineFriendsCounter(counters.value("online_friends").toInt());
//        if (counters.contains("mutual_friends")) user->setMutualFriendsCounter(counters.value("mutual_friends").toInt());
//        if (counters.contains("user_videos")) user->setUserVideosCounter(counters.value("user_videos").toInt());
//        if (counters.contains("followers")) user->setFollowersCounter(counters.value("followers").toInt());
//        if (counters.contains("pages")) user->setPagesCounter(counters.value("pages").toInt());
//    }

    return user;
}

int User::id() const
{
    return _id;
}

void User::setId(int id)
{
    _id = id;
}

QString User::deactivated() const
{
    return _deactivated;
}

void User::setDeactivated(const QString &deactivated)
{
    _deactivated = deactivated;
}

bool User::blacklisted() const
{
    return _blacklisted;
}

void User::setBlacklisted(bool blacklisted)
{
    _blacklisted = blacklisted;
}

bool User::blacklistedByMe() const
{
    return _blacklistedByMe;
}

void User::setBlacklistedByMe(bool blacklistedByMe)
{
    _blacklistedByMe = blacklistedByMe;
}

bool User::canPost() const
{
    return _canPost;
}

void User::setCanPost(bool canPost)
{
    _canPost = canPost;
}

bool User::canSeeAllPosts() const
{
    return _canSeeAllPosts;
}

void User::setCanSeeAllPosts(bool canSeeAllPosts)
{
    _canSeeAllPosts = canSeeAllPosts;
}

bool User::canSeeAudio() const
{
    return _canSeeAudio;
}

void User::setCanSeeAudio(bool canSeeAudio)
{
    _canSeeAudio = canSeeAudio;
}

bool User::canSendFriendRequest() const
{
    return _canSendFriendRequest;
}

void User::setCanSendFriendRequest(bool canSendFriendRequest)
{
    _canSendFriendRequest = canSendFriendRequest;
}

bool User::canWritePrivateMessage() const
{
    return _canWritePrivateMessage;
}

void User::setCanWritePrivateMessage(bool canWritePrivateMessage)
{
    _canWritePrivateMessage = canWritePrivateMessage;
}

QString User::domain() const
{
    return _domain.isEmpty() ? QString("id%1").arg(_id) : _domain;
}

void User::setDomain(const QString &domain)
{
    _domain = domain;
}

int User::friendStatus() const
{
    return _friendStatus;
}

void User::setFriendStatus(int friendStatus)
{
    _friendStatus = friendStatus;
}

bool User::isFavorite() const
{
    return _isFavorite;
}

void User::setIsFavorite(bool isFavorite)
{
    _isFavorite = isFavorite;
}

bool User::isHiddenFromFeed() const
{
    return _isHiddenFromFeed;
}

void User::setIsHiddenFromFeed(bool isHiddenFromFeed)
{
    _isHiddenFromFeed = isHiddenFromFeed;
}

QString User::photoMaxOrig() const
{
    return _photoMaxOrig;
}

void User::setPhotoMaxOrig(const QString &photoMaxOrig)
{
    _photoMaxOrig = photoMaxOrig;
}

bool User::getVerified() const
{
    return verified;
}

void User::setVerified(bool value)
{
    verified = value;
}
