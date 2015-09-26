// Copyright 2015 Klimov Viktor, https://github.com/Vitek1425/

#include "angulargauge.h"
#include <QPainter>
#include <qmath.h>

AngularGauge::AngularGauge(QWidget *parent)
    : QWidget(parent),
      m_value(0),
      m_minimumValue(0),
      m_maximumValue(100),
      m_scaleIsEnabled(true),
      m_numberBigScaleDivisions(5),
      m_numberSmallScaleDivisions(4),
      m_beginningScaleDegree(-60),
      m_endingScaleDegree(240),
      m_proportionBigScale(1./6),
      m_proportionSmallScale(1./8),
      m_proportionScaleRange(1./8),
      m_gaugeStyle(standart),
      m_directionArrow(clockwise),
      m_margins(3, 3, 3, 3),
      m_faceBrush(Qt::white),
      m_scaleColor(QColor(128, 128, 128)),
      m_frameBorderColor(QColor(138, 138, 138)),
      m_frameInsideColor(QColor(204, 204, 204)),
      m_beginningFrameDegree(-60),
      m_endingFrameDegree(240),
      m_markerColor(QColor(186, 62, 50)),
      m_proportionMarker(6./8),
      m_proportionSmallCircle(0.5),
      m_faceRadiusProportion(0.9),
      m_frameSizeProportion(0.1)
{
    setAttribute(Qt::WA_AlwaysShowToolTips);
    setToolTip(QString::number(m_value));
    computePaintArea();
    updateFrame();
    updateMarker();
    setMinimumSize(90, 90);
}

AngularGauge::~AngularGauge()
{

}

qreal AngularGauge::getValue() const
{
    return m_value;
}

qreal AngularGauge::getMinimumValue() const
{
    return m_minimumValue;
}

qreal AngularGauge::getMaximumValue() const
{
    return m_maximumValue;
}

bool AngularGauge::scaleIsEnabled() const
{
    return m_scaleIsEnabled;
}

void AngularGauge::setScaleIsEnabled(bool scaleIsEnabled)
{
    m_scaleIsEnabled = scaleIsEnabled;
    update();
}

int AngularGauge::getNumberBigScaleDivisions() const
{
    return m_numberBigScaleDivisions;
}

void AngularGauge::setNumberBigScaleDivisions(int numberBigScaleDivisions)
{
    if(numberBigScaleDivisions < 1)
        return;
    m_numberBigScaleDivisions = numberBigScaleDivisions;
    update();
}


int AngularGauge::getNumberSmallScaleDivisions() const
{
    return m_numberSmallScaleDivisions;
}

void AngularGauge::setNumberSmallScaleDivisions(int numberSmallScaleDivisions)
{
    if(numberSmallScaleDivisions < 1)
        return;
    m_numberSmallScaleDivisions = numberSmallScaleDivisions;
    update();
}

qreal AngularGauge::getBeginningScaleDegree() const
{
    return m_beginningScaleDegree;
}

void AngularGauge::setBeginningScaleDegree(const qreal &beginningScaleDegree)
{
    m_beginningScaleDegree = beginningScaleDegree;
    updateFrame();
    update();
}

qreal AngularGauge::getEndingScaleDegree() const
{
    return m_endingScaleDegree;
}

void AngularGauge::setEndingScaleDegree(const qreal &endingScaleDegree)
{
    m_endingScaleDegree = endingScaleDegree;
    updateFrame();
    update();
}

qreal AngularGauge::getProportionBigScale() const
{
    return m_proportionBigScale;
}

void AngularGauge::setProportionBigScale(const qreal &proportionBigScale)
{
    if(!checkInRange(proportionBigScale))
        return;
    m_proportionBigScale = proportionBigScale;
    update();
}

qreal AngularGauge::getProportionSmallScale() const
{
    return m_proportionSmallScale;
}

void AngularGauge::setProportionSmallScale(const qreal &proportionSmallScale)
{
    if(!checkInRange(proportionSmallScale))
        return;
    m_proportionSmallScale = proportionSmallScale;
    update();
}

qreal AngularGauge::getProportionScaleRange() const
{
    return m_proportionScaleRange;
}

void AngularGauge::setProportionScaleRange(const qreal &proportionScaleRange)
{
    if (!checkInRange(proportionScaleRange))
        return;
    m_proportionScaleRange = proportionScaleRange;
    update();
}

AngularGauge::GaugeStyle AngularGauge::getGaugeStyle() const
{
    return m_gaugeStyle;
}

void AngularGauge::setGaugeStyle(const GaugeStyle &gaugeStyle)
{
    m_gaugeStyle = gaugeStyle;
    updateFrame();
    updateMarker();
    update();
}

AngularGauge::DirectionArrow AngularGauge::getDirectionArrow() const
{
    return m_directionArrow;
}

void AngularGauge::setDirectionArrow(const DirectionArrow &directionArrow)
{
    m_directionArrow = directionArrow;
    update();
}


QMarginsF AngularGauge::getMargins() const
{
    return m_margins;
}

void AngularGauge::setMargins(const QMarginsF &margins)
{
    m_margins = margins;
    setMinimumSize(90 + m_margins.left() + m_margins.right(),
                   90 + m_margins.bottom() + m_margins.top());
    updateFrame();
    updateMarker();
    update();
}

QBrush AngularGauge::getFaceBrush() const
{
    return m_faceBrush;
}

void AngularGauge::setFaceBrush(const QBrush &faceBrush)
{
    m_faceBrush = faceBrush;
    update();
}

QColor AngularGauge::getScaleColor() const
{
    return m_scaleColor;
}

void AngularGauge::setScaleColor(const QColor &scaleColor)
{
    m_scaleColor = scaleColor;
    update();
}

QColor AngularGauge::getFrameBorderColor() const
{
    return m_frameBorderColor;
}

void AngularGauge::setFrameBorderColor(const QColor &frameBorderColor)
{
    m_frameBorderColor = frameBorderColor;
    update();
}

QColor AngularGauge::getFrameInsideColor() const
{
    return m_frameInsideColor;
}

void AngularGauge::setFrameInsideColor(const QColor &frameInsideColor)
{
    m_frameInsideColor = frameInsideColor;
    update();
}

qreal AngularGauge::getBeginningFrameDegree() const
{
    return m_beginningFrameDegree;
}

void AngularGauge::setBeginningFrameDegree(const qreal &beginningFrameDegree)
{
    m_beginningFrameDegree = beginningFrameDegree;
    updateFrame();
    update();
}

qreal AngularGauge::getEndingFrameDegree() const
{
    return m_endingFrameDegree;
}

void AngularGauge::setEndingFrameDegree(const qreal &endingFrameDegree)
{
    m_endingFrameDegree = endingFrameDegree;
    updateFrame();
    update();
}

QColor AngularGauge::getMarkerColor() const
{
    return m_markerColor;
}

void AngularGauge::setMarkerColor(const QColor &markerColor)
{
    m_markerColor = markerColor;
    update();
}

qreal AngularGauge::getProportionMarker() const
{
    return m_proportionMarker;
}

void AngularGauge::setProportionMarker(const qreal &proportionMarker)
{
    if (!checkInRange(proportionMarker))
        return;
    m_proportionMarker = proportionMarker;
    update();
}

qreal AngularGauge::getProportionSmallCircle() const
{
    return m_proportionSmallCircle;
}

void AngularGauge::setProportionSmallCircle(const qreal &proportionSmallCircle)
{
    if(!checkInRange(proportionSmallCircle))
        return;
    m_proportionSmallCircle = proportionSmallCircle;
    update();
}

qreal AngularGauge::getFaceRadiusProportion() const
{
    return m_faceRadiusProportion;
}

void AngularGauge::setFaceRadiusProportion(const qreal &faceRadiusProportion)
{
    if(!checkInRange(faceRadiusProportion))
        return;
    m_faceRadiusProportion = faceRadiusProportion;
    update();
}

qreal AngularGauge::getFrameSizeProportion() const
{
    return m_frameSizeProportion;
}

void AngularGauge::setFrameSizeProportion(const qreal &frameSizeProportion)
{
    if(!checkInRange(frameSizeProportion))
        return;
    m_frameSizeProportion = frameSizeProportion;
    update();
}

void AngularGauge::addScaleRange(const ScaleRange &range)
{
    m_scaleRanges.append(range);
    update();
}

void AngularGauge::clearScaleRangesList()
{
    m_scaleRanges.clear();
    update();
}

void AngularGauge::setValue(qreal value)
{
    if((m_value == value) ||
      (value < m_minimumValue) ||
      (value > m_maximumValue))
        return;
    m_value = value;
    setToolTip(QString::number(m_value));
    emit valueChanged(value);
    update();
}

void AngularGauge::setMinimumValue(qreal value)
{
    m_minimumValue = value;
    update();
}

void AngularGauge::setMaximumValue(qreal value)
{
    m_maximumValue = value;
    update();
}

void AngularGauge::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    drawFace(&painter);
    drawScaleRanges(&painter);
    drawScale(&painter);
    drawFrame(&painter);
    drawNumebrs(&painter);
    drawMarker(&painter);
}

void AngularGauge::resizeEvent(QResizeEvent *)
{
    computePaintArea();
    updateFrame();
    updateMarker();
}

QSize AngularGauge::sizeHint() const
{
    return QSize(180, 180);
}

void AngularGauge::drawFace(QPainter *painter)
{
    painter->save();

    painter->setBrush(m_faceBrush);
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_faceBrush);
    int faceRadius = computeFaceRadius();
    QPointF centerFace(m_paintArea.x() + m_paintArea.width() / 2,
                       m_paintArea.y() + m_paintArea.height() / 2);

    switch (m_gaugeStyle) {
    case standart:
    {
        painter->drawEllipse(centerFace, faceRadius, faceRadius);
    }
        break;
    case arc:
    {
        painter->drawChord(QRectF(centerFace.x() - faceRadius,
                                  centerFace.y() - faceRadius,
                                  2 * faceRadius, 2 * faceRadius),
                            m_beginningFrameDegree * 16,
                            (m_endingFrameDegree  - m_beginningFrameDegree)* 16);
        painter->drawEllipse(centerFace,
                             m_proportionSmallCircle * faceRadius,
                             m_proportionSmallCircle * faceRadius);
    }
        break;
    case pie:
    {
        painter->drawPie(QRectF(centerFace.x() - faceRadius,
                                centerFace.y() - faceRadius,
                                 2 * faceRadius, 2 * faceRadius),
                          m_beginningFrameDegree * 16,
                          (m_endingFrameDegree  - m_beginningFrameDegree) * 16);
        painter->drawEllipse(centerFace,
                             m_proportionSmallCircle * faceRadius,
                             m_proportionSmallCircle * faceRadius);
        break;
    }
    }

    painter->restore();
}

void AngularGauge::drawFrame(QPainter *painter)
{
    painter->save();
    int frameWidth = m_frameSizeProportion * m_paintArea.width();
    //изображение внешней стороны рамки
    painter->setPen(QPen(m_frameBorderColor, frameWidth / 2));
    painter->drawPath(m_frame);

    //изображение внутреннемй стороны рамки
    painter->setPen(QPen(m_frameInsideColor, frameWidth / 2 - 0.025 * m_paintArea.width()));
    painter->drawPath(m_frame);

    painter->restore();
}

void AngularGauge::drawScaleRanges(QPainter *painter)
{
    if(m_scaleRanges.isEmpty())
        return;
    painter->save();

    qreal scaleRangeWidth = m_proportionScaleRange * m_paintArea.width();
    qreal scaleRangesRadius = 2 * computeFaceRadius() + 2 * computeFrameWidth() - scaleRangeWidth;
    QRectF scaleRangesArea(m_paintArea.x() + m_paintArea.width() / 2 - computeFaceRadius() - computeFrameWidth() + scaleRangeWidth / 2,
                           m_paintArea.y() + m_paintArea.height() / 2 - computeFaceRadius() - computeFrameWidth() + scaleRangeWidth / 2,
                           scaleRangesRadius,
                           scaleRangesRadius);

    for(int i = 0; i < m_scaleRanges.size(); ++i)
    {
        qreal beginDegree = valueToDegree(m_scaleRanges.at(i).beginValue);
        qreal endDegree = valueToDegree(m_scaleRanges.at(i).endValue) - beginDegree;
        painter->setPen(QPen(QBrush(m_scaleRanges.at(i).color), scaleRangeWidth / 2, Qt::SolidLine, Qt::FlatCap));
        painter->drawArc(scaleRangesArea,
                         beginDegree * 16,
                         endDegree * 16);
    }

    painter->restore();
}

void AngularGauge::drawScale(QPainter *painter)
{
    if (!m_scaleIsEnabled)
        return;

    painter->save();
    //перенос в центр
    painter->translate(QPointF(m_paintArea.x() + m_paintArea.width()/2,
                               m_paintArea.y() + m_paintArea.height()/2));
    int faceRadius = computeFaceRadius();

    qreal stepDegree = (m_endingScaleDegree - m_beginningScaleDegree)/
                       (m_numberBigScaleDivisions * m_numberSmallScaleDivisions);
    for(int i = 0; i < m_numberBigScaleDivisions * m_numberSmallScaleDivisions + 1; ++i)
    {
        qreal radianAngle = qDegreesToRadians(m_beginningScaleDegree + stepDegree * i);
        QPointF navigationScale(qCos(radianAngle), -qSin(radianAngle));

        if (i % m_numberSmallScaleDivisions == 0)
        {
            //изображение большой шкалы
            painter->setPen(QPen(m_scaleColor, 0.008 * m_paintArea.width()));
            painter->drawLine(faceRadius * (1 - m_proportionBigScale) * navigationScale,
                              faceRadius * navigationScale);
        }
        else
        {
            //изображение маленькой шкалы
            painter->setPen(QPen(m_scaleColor, 0.004 * m_paintArea.width()));
            painter->drawLine(faceRadius * (1 - m_proportionSmallScale) * navigationScale,
                              faceRadius * navigationScale);
        }
    }

    painter->restore();
}

void AngularGauge::drawNumebrs(QPainter *painter)
{
    painter->save();
    int faceRadius = computeFaceRadius();
    painter->setPen(palette().text().color());
    painter->setFont(font());

    painter->translate(QPointF(m_paintArea.x() + m_paintArea.width()/2,
                               m_paintArea.y() + m_paintArea.height()/2));
    QFontMetrics fontMetrics(font());
    qreal stepDegreeAngle = (m_endingScaleDegree - m_beginningScaleDegree)/m_numberBigScaleDivisions;
    qreal stepDegreeValue = (m_maximumValue - m_minimumValue) / m_numberBigScaleDivisions;
    int heightString = fontMetrics.height();

    if(m_directionArrow == counterclockwise)
    for(int i = 0; i <= m_numberBigScaleDivisions; i++)
    {
        qreal curentRadianAngle = qDegreesToRadians(m_beginningScaleDegree + i * stepDegreeAngle);
        qreal rangeText = faceRadius - heightString - faceRadius / 6;
        drawText(painter, QPointF(-rangeText * - qCos(curentRadianAngle),
                                  -rangeText * qSin(curentRadianAngle)),
                                  QString::number(m_minimumValue + stepDegreeValue * i));
    }
    else // (m_directionArrow == clockwise)
    for(int i = 0; i <= m_numberBigScaleDivisions; i++)
    {
        qreal curentRadianAngle = qDegreesToRadians(m_beginningScaleDegree + i * stepDegreeAngle);
        qreal rangeText = faceRadius - heightString - faceRadius / 6;
        drawText(painter, QPointF(-rangeText * - qCos(curentRadianAngle),
                                  -rangeText * qSin(curentRadianAngle)),
                                  QString::number(m_maximumValue - stepDegreeValue * i));
    }

    painter->restore();
}

void AngularGauge::drawMarker(QPainter *painter)
{
    painter->save();

    painter->setTransform(QTransform(1, 0, 0,
                                     0, -1, 0,
                                     0, 1, 1));
    painter->setPen(Qt::NoPen);
    painter->setBrush(m_markerColor);
    painter->translate(QPointF(m_paintArea.x() + m_paintArea.width()/2,
                               -(m_paintArea.y() + m_paintArea.height()/2)));
    qreal angleArrowDegree = valueToDegree(m_value);
    painter->rotate(angleArrowDegree + 90);
    painter->drawPath(m_marker);

    painter->restore();
}

void AngularGauge::drawText(QPainter *painter, const QPointF &point, const QString &string)
{
    QFontMetrics fontMetrics(font());
    int widthString = fontMetrics.width(string);
    int hegthString = fontMetrics.height();
    painter->drawText(QRectF(point.x() - widthString,
                      point.y() - hegthString ,
                      2 * widthString,
                      2 * hegthString),
                      Qt::AlignCenter,
                      string);
}

qreal AngularGauge::valueToDegree(qreal value)
{
    if(m_directionArrow == counterclockwise)
    {
        return m_beginningScaleDegree  + (m_endingScaleDegree - m_beginningScaleDegree) *
                          (value - m_minimumValue) / (m_maximumValue - m_minimumValue);
    }
    else //== clockwise
    {
        return  m_endingScaleDegree  + (m_beginningScaleDegree - m_endingScaleDegree) *
                          (value - m_minimumValue) / (m_maximumValue - m_minimumValue);
    }
}

bool AngularGauge::checkInRange(qreal value)
{
    return ((value >= 0) && (value <= 1));
}

void AngularGauge::computePaintArea()
{
    int sizeSquare = qMin(width() - m_margins.left() - m_margins.right(),
                          height() - m_margins.top() - m_margins.bottom());

    //вычисление положения квадрата в центре между отступами
    m_paintArea = QRect(m_margins.left() + (width() - m_margins.left() - m_margins.right()) / 2 - sizeSquare / 2,
                         m_margins.top() + (height() - m_margins.top() - m_margins.bottom()) / 2 - sizeSquare / 2,
                         sizeSquare,
                         sizeSquare);
}

void AngularGauge::updateFrame()
{
    switch (m_gaugeStyle) {
    case standart:
    {
        QPainterPath frame;
        QPointF centerFrame(m_paintArea.x() + m_paintArea.width() / 2,
                            m_paintArea.y() + m_paintArea.height() / 2);
        int frameRadius = computeFaceRadius() + computeFrameWidth() / 2;

        frame.addEllipse(centerFrame, frameRadius, frameRadius);
        m_frame = frame;
        break;
    }
    case pie:
    {
        QPainterPath frame;
        QPointF centerFrame(m_paintArea.x() + m_paintArea.width() / 2,
                            m_paintArea.y() + m_paintArea.height() / 2);
        int frameRadius = computeFaceRadius() + computeFrameWidth() / 2;

        frame.moveTo(centerFrame);
        frame.arcTo(QRectF(centerFrame.x() - frameRadius,
                    centerFrame.y() - frameRadius,
                    2 * frameRadius,
                    2 * frameRadius),
                    m_beginningFrameDegree,
                    m_endingFrameDegree - m_beginningFrameDegree);
        frame.closeSubpath();
        //добавление окружности в центр
        if (m_proportionSmallCircle > 0)
        {
            QPainterPath circlePath;
            circlePath.addEllipse(centerFrame,
                                  m_proportionSmallCircle * computeFaceRadius(),
                                  m_proportionSmallCircle * computeFaceRadius());
            frame = frame + circlePath;
        }
        m_frame = frame;
        break;

    }
    case arc:
    {
        QPainterPath frame;
        //перенос точки в середину отсечения
        qreal beginningFrameRadian = qDegreesToRadians(m_beginningFrameDegree);
        qreal endingFrameRadian = qDegreesToRadians(m_endingFrameDegree);
        QPointF centerFrame(m_paintArea.x() + m_paintArea.width() / 2,
                            m_paintArea.y() + m_paintArea.height() / 2);
        int frameRadius = computeFaceRadius() + computeFrameWidth() / 2;

        frame.moveTo(centerFrame.x() +
                     0.5 * (qCos(beginningFrameRadian) + qCos(endingFrameRadian)) * frameRadius,
                     centerFrame.y() -
                     0.5 * (qSin(beginningFrameRadian) + qSin(endingFrameRadian)) * frameRadius);
        frame.arcTo(QRectF(centerFrame.x() - frameRadius,
                      centerFrame.y() - frameRadius,
                      2 * frameRadius,
                      2 * frameRadius),
                      m_beginningFrameDegree,
                      m_endingFrameDegree - m_beginningFrameDegree);
        frame.closeSubpath();
        //добавление окружности в центр
        if (m_proportionSmallCircle > 0)
        {
            QPainterPath circlePath;
            circlePath.addEllipse(centerFrame,
                                  m_proportionSmallCircle * computeFaceRadius(),
                                  m_proportionSmallCircle * computeFaceRadius());
            frame = frame + circlePath;
        }
        m_frame = frame;
        break;
    }
    }
}

void AngularGauge::updateMarker()
{
    QPainterPath marker;
    qreal sizeCellMarker = m_proportionMarker * m_paintArea.height() / 144;
    QPolygon arrowPolygon;
    arrowPolygon << QPoint(sizeCellMarker * 3, 0) <<
                     QPoint(sizeCellMarker * 7, 0) <<
                     QPoint(sizeCellMarker * 8, sizeCellMarker * 72) <<
                     QPoint(sizeCellMarker * 2, sizeCellMarker * 72);

    marker.addPolygon(arrowPolygon);
    QPainterPath circle;
    circle.addEllipse(QPointF(sizeCellMarker * 5, sizeCellMarker * 72),
                      sizeCellMarker * 5.5, sizeCellMarker * 5.5);
    QPainterPath holeCircle;
    holeCircle.addEllipse(QPointF(sizeCellMarker * 5, sizeCellMarker * 72),
                      sizeCellMarker * 3, sizeCellMarker * 3);
    m_marker = marker + circle - holeCircle;
    m_marker.translate(-sizeCellMarker * 5, -sizeCellMarker * 72);
}

int AngularGauge::computeFaceRadius()
{
    return static_cast<int>(m_faceRadiusProportion * m_paintArea.width() / 2);
}

int AngularGauge::computeFrameWidth()
{
    return static_cast<int>(m_frameSizeProportion * m_paintArea.width() / 2);
}
