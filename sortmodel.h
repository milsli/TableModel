#ifndef SORTMODEL_H
#define SORTMODEL_H

#include <QSortFilterProxyModel>

class SortModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    SortModel(QObject *parent = nullptr);
};

#endif // SORTMODEL_H
