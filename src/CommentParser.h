/**
 * Copyright (C) 2019 Michael Reeves <reeves.87@gmail.com>
 *
 * This file is part of KDiff3.
 *
 * KDiff3 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * KDiff3 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with KDiff3.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef COMMENTPARSER_H
#define COMMENTPARSER_H

#include <QChar>
#include <QString>

class CommentParser
{
  public:
    inline virtual void proccessChar(const QString &line, const QChar &inChar) = 0;
    inline virtual bool inComment() const = 0;
    inline virtual bool isPureComment() const = 0;
    inline virtual void removeComments() = 0;
    virtual ~CommentParser(){};
};

class DefaultCommentParser : public CommentParser
{
  public:
    virtual void proccessChar(const QString &line, const QChar &inChar) override;

    inline bool inComment() const override { return mInComment; };
    inline bool isPureComment() const override { return mIsPureComment; };
    inline void removeComments() override;

  private:
    QChar mLastChar = QChar(0); //character that started current string.
    bool mInString = false, mInComment = false;
    bool mIsPureComment = false;
};

#endif // !COMMENTPASER_H
