//ghia48.serhan@gmail.com
#include "TreeWidget.h"
#include <QPaintEvent>
#include <QPainter>

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent) {}

void TreeWidget::setTreeData(const std::vector<std::tuple<int, int>> &data) {
    treeData = data;
    update();
}

void TreeWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int nodeRadius = 10;
    int xStep = 40;
    int depthSpacing = 100;

    // Calculate the width and height of the tree
    int maxDepth = 0;
    int maxWidth = 0;
    for (const auto &[key, depth] : treeData) {
        if (depth > maxDepth) {
            maxDepth = depth;
        }
        if (key > maxWidth) {
            maxWidth = key;
        }
    }

    int treeWidth = (maxWidth + 1) * xStep;
    int treeHeight = (maxDepth + 1) * depthSpacing;

    // Calculate offsets to center the tree in the widget
    int xOffset = (width() - treeWidth) / 2;
    int yOffset = (height() - treeHeight) / 2;

    for (const auto &[key, depth] : treeData) {
        int y = yOffset + depth * depthSpacing;
        int x = xOffset + key * xStep; // Adjust x position for better visualization
        painter.drawEllipse(QPointF(x, y), nodeRadius, nodeRadius);
        painter.drawText(QRect(x - nodeRadius, y - nodeRadius, 2 * nodeRadius, 2 * nodeRadius),
                         Qt::AlignCenter, QString::number(key));
    }

    // Optional: Draw lines connecting the nodes
    painter.setPen(Qt::black);
    for (size_t i = 0; i < treeData.size(); ++i) {
        int currentX = xOffset + std::get<0>(treeData[i]) * xStep;
        int currentY = yOffset + std::get<1>(treeData[i]) * depthSpacing;

        if (i * 2 + 1 < treeData.size()) {
            int leftChildX = xOffset + std::get<0>(treeData[i * 2 + 1]) * xStep;
            int leftChildY = yOffset + std::get<1>(treeData[i * 2 + 1]) * depthSpacing;
            painter.drawLine(currentX, currentY, leftChildX, leftChildY);
        }

        if (i * 2 + 2 < treeData.size()) {
            int rightChildX = xOffset + std::get<0>(treeData[i * 2 + 2]) * xStep;
            int rightChildY = yOffset + std::get<1>(treeData[i * 2 + 2]) * depthSpacing;
            painter.drawLine(currentX, currentY, rightChildX, rightChildY);
        }
    }
}
