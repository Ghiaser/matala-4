//ghia48.serhan@gmail.com
#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <tuple>
#include <vector>

class TreeWidget : public QWidget {
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = nullptr);

    void setTreeData(const std::vector<std::tuple<int, int>> &data);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::tuple<int, int>> treeData;
};

#endif
