// SPDX-FileCopyrightText: 2022 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef ADVANCESEARCHBAR_P_H
#define ADVANCESEARCHBAR_P_H

#include "dfmplugin_search_global.h"

#include "dfm-base/interfaces/abstractfileinfo.h"

#include <dboxwidget.h>

#include <QDateTime>

#include <mutex>

DWIDGET_BEGIN_NAMESPACE
class DCommandLinkButton;
DWIDGET_END_NAMESPACE

QT_BEGIN_NAMESPACE
class QLabel;
class QComboBox;
QT_END_NAMESPACE

using FilterCallback = std::function<bool(DFMBASE_NAMESPACE::AbstractFileInfo *info, QVariant data)>;

namespace dfmplugin_search {

class AdvanceSearchBar;
class AdvanceSearchBarPrivate : public DTK_WIDGET_NAMESPACE::DBoxWidget
{
    Q_OBJECT
public:
    enum LabelIndex {
        kSearchRange,
        kFileType,
        kSizeRange,
        kDateRange,
        kAccessDateRange,
        kCreateDateRange,
        kLabelCount,
        kCurrentUrl
    };

    typedef struct fileFilter
    {
        QPair<quint64, quint64> sizeRange;
        QDateTime dateRangeStart;
        QDateTime dateRangeEnd;
        QDateTime accessDateRangeStart;
        QDateTime accessDateRangeEnd;
        QDateTime createDateRangeStart;
        QDateTime createDateRangeEnd;
        QString typeString;
        QUrl currentUrl;
        bool includeSubDir;
        bool comboValid[kLabelCount];
    } FileFilter;

    explicit AdvanceSearchBarPrivate(AdvanceSearchBar *qq);
    void initUI();
    void initConnection();
    void refreshOptions(const QUrl &url);

    static bool shouldVisiableByFilterRule(DFMBASE_NAMESPACE::AbstractFileInfo *info, QVariant data);
    static FileFilter parseFilterData(const QMap<int, QVariant> &data);

    QBoxLayout *mainLayout;
    QLabel *asbLabels[kLabelCount];
    QComboBox *asbCombos[kLabelCount];
    DTK_WIDGET_NAMESPACE::DCommandLinkButton *resetBtn;

    using FilterData = QMap<int, QVariant>;
    using FilterInfoCache = QHash<QUrl, FilterData>;
    FilterInfoCache filterInfoCache;

    AdvanceSearchBar *q;
};

}

Q_DECLARE_METATYPE(FilterCallback)

#endif   // ADVANCESEARCHBAR_P_H