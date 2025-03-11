/*
    KWin - the KDE window manager
    This file is part of the KDE project.

    SPDX-FileCopyrightText: 2014 Martin Gräßlin <mgraesslin@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include "options.h"

#include <KDecoration2/Private/DecoratedWindowPrivate>

#include <QDeadlineTimer>
#include <QObject>
#include <QTimer>

namespace KWin
{

class Window;

namespace Decoration
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
class DecoratedWindowImpl : public QObject, public KDecoration2::DecoratedWindowPrivate
#else
class DecoratedWindowImpl : public QObject, public KDecoration2::DecoratedWindowPrivateV2
#endif
{
    Q_OBJECT
public:
    explicit DecoratedWindowImpl(Window *window, KDecoration2::DecoratedWindow *decoratedClient, KDecoration2::Decoration *decoration);
    ~DecoratedWindowImpl() override;
    QString caption() const override;
    qreal height() const override;
    QIcon icon() const override;
    bool isActive() const override;
    bool isCloseable() const override;
    bool isKeepAbove() const override;
    bool isKeepBelow() const override;
    bool isMaximizeable() const override;
    bool isMaximized() const override;
    bool isMaximizedHorizontally() const override;
    bool isMaximizedVertically() const override;
    bool isMinimizeable() const override;
    bool isModal() const override;
    bool isMoveable() const override;
    bool isOnAllDesktops() const override;
    bool isResizeable() const override;
    bool isShadeable() const override;
    bool isShaded() const override;
    QPalette palette() const override;
    QColor color(KDecoration2::ColorGroup group, KDecoration2::ColorRole role) const override;
    bool providesContextHelp() const override;
    QSizeF size() const override;
    qreal width() const override;
    QString windowClass() const override;
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    qreal scale() const override;
    qreal nextScale() const override;
    QString applicationMenuServiceName() const override;
    QString applicationMenuObjectPath() const override;
#endif
    Qt::Edges adjacentScreenEdges() const override;

    bool hasApplicationMenu() const override;
    bool isApplicationMenuActive() const override;

    void requestShowToolTip(const QString &text) override;
    void requestHideToolTip() override;
    void requestClose() override;
    void requestContextHelp() override;
    void requestToggleMaximization(Qt::MouseButtons buttons) override;
    void requestMinimize() override;
    void requestShowWindowMenu(const QRect &rect) override;
    void requestShowApplicationMenu(const QRect &rect, int actionId) override;
    void requestToggleKeepAbove() override;
    void requestToggleKeepBelow() override;
    void requestToggleOnAllDesktops() override;
    void requestToggleShade() override;

    void showApplicationMenu(int actionId) override;

    Window *window()
    {
        return m_window;
    }
    KDecoration2::DecoratedWindow *decoratedWindow()
    {
        return KDecoration2::DecoratedWindowPrivate::window();
    }

    void signalShadeChange();

private Q_SLOTS:
    void delayedRequestToggleMaximization(Options::WindowOperation operation);

private:
    Window *m_window;
    QSizeF m_clientSize;

    QString m_toolTipText;
    QTimer m_toolTipWakeUp;
    QDeadlineTimer m_toolTipFallAsleep;
    bool m_toolTipShowing = false;
};

}
}
