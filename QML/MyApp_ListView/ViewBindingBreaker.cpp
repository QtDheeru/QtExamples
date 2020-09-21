#include "ViewBindingBreaker.h"

ViewBindingBreaker::ViewBindingBreaker(QObject *parent) : QObject(parent)
{

}

int ViewBindingBreaker::topIndex() const
{
    qDebug() << Q_FUNC_INFO << " Top Index =" << m_topIndex <<endl;
    return m_topIndex;
}

void ViewBindingBreaker::setTopIndex(int topIndex)
{
    m_topIndex = topIndex;
    if (m_bottomIndex != m_topIndex){
        moveBottomView(m_topIndex);
    }
    qDebug() << Q_FUNC_INFO << " Top Index =" << m_topIndex <<endl;
}

int ViewBindingBreaker::bottomIndex() const
{
    qDebug() << Q_FUNC_INFO << " Bottom Index =" << m_bottomIndex <<endl;
    return m_bottomIndex;
}

void ViewBindingBreaker::setBottomIndex(int bottomIndex)
{
    m_bottomIndex = bottomIndex;
    if (m_topIndex != m_bottomIndex){
        moveTopView(m_bottomIndex);
    }
    qDebug() << Q_FUNC_INFO << " Bottom Index =" << m_bottomIndex <<endl;
}
