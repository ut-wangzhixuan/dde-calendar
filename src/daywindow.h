/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     kirigaya <kirigaya@mkacg.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DAYWINDOW_H
#define DAYWINDOW_H

#include <QWidget>
#include <DMainWindow>
#include <QDate>
#include <DLabel>
#include <DFrame>
#include "calendardbus.h"
DWIDGET_USE_NAMESPACE

class CDayMonthView;
class CScheduleView;
class CSchceduleSearchView;
class CDayWindow: public QMainWindow
{
    Q_OBJECT
public:
    CDayWindow(QWidget *parent = 0);
    ~CDayWindow();
    void setDate(QDate date);
    void setSearchWFlag(bool flag);
    void clearSearch();
    void setSearchText(QString str);
    void setLunarVisible(bool state);
    void setTheMe(int type = 0);
private:
    void initUI();
    void initConnection();
signals:
    void dateSelected(const QDate date, const CaLunarDayInfo &detail) const;
    void signalsWUpdateShcedule(QMainWindow *w, int id = 0);
    void signalsReturnTodayUpdate(QMainWindow *w);
public slots:
    void slotupdateSchedule(int id = 0);
    void slotTransitSchedule(int id = 0);
    void slotTransitSearchSchedule(int id = 0);
    void slotReturnTodayUpdate();
    void slotCurrentReturnDay();
protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void slotcurrentDateLunarChanged(QDate date,  CaHuangLiDayInfo detail, int type = 0);
    void slotcurrentDateChanged(QDate date);
private:
    CDayMonthView     *m_daymonthView;
    DFrame *m_contentBackground = nullptr;
    DFrame *m_leftground = nullptr;
    QDate              m_currentdate;
    DLabel            *m_YearLabel;
    DLabel            *m_LunarLabel;
    DLabel            *m_SolarDay;
    CScheduleView     *m_scheduleView;
    CSchceduleSearchView *m_schceduleSearchView;
    QString           m_searchText;
};

#endif // YEARWINDOW_H
