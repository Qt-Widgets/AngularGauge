// Copyright 2015 Klimov Viktor, https://github.com/Vitek1425/

#ifndef ANGULARGAUGE_H
#define ANGULARGAUGE_H

#include <QWidget>

struct ScaleRange
{
    ScaleRange(): beginValue(0), endValue(0), color(Qt::red)
    {
    }
    ScaleRange(qreal beginValue, qreal endValue, const QColor &color = QColor(Qt::red)):
        beginValue(beginValue), endValue(endValue), color(color)
    {
    }
    qreal beginValue;
    qreal endValue;
    QColor color;
};

class AngularGauge : public QWidget
{
    Q_OBJECT

    Q_ENUMS(GaugeStyle)
    Q_ENUMS(DirectionArrow)

    Q_PROPERTY(qreal value READ getValue WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(qreal minimumValue READ getMinimumValue WRITE setMinimumValue)
    Q_PROPERTY(qreal maximumValue READ getMaximumValue WRITE setMaximumValue)
    Q_PROPERTY(bool scaleIsEnabled READ scaleIsEnabled WRITE setScaleIsEnabled)
    Q_PROPERTY(int numberBigScaleDivisions READ getNumberBigScaleDivisions WRITE setNumberBigScaleDivisions)
    Q_PROPERTY(int numberSmallScaleDivisions READ getNumberSmallScaleDivisions WRITE setNumberSmallScaleDivisions)
    Q_PROPERTY(qreal beginningScaleDegree READ getBeginningScaleDegree WRITE setBeginningScaleDegree)
    Q_PROPERTY(qreal endingScaleDegree READ getEndingScaleDegree WRITE setEndingScaleDegree)
    Q_PROPERTY(qreal proportionBigScale READ getProportionBigScale WRITE setProportionBigScale)
    Q_PROPERTY(qreal proportionSmallScale READ getProportionSmallScale WRITE setProportionSmallScale)
    Q_PROPERTY(qreal proportionScaleRange READ getProportionScaleRange WRITE setProportionScaleRange)
    Q_PROPERTY(GaugeStyle gaugeStyle READ getGaugeStyle WRITE setGaugeStyle)
    Q_PROPERTY(DirectionArrow directionArrow READ getDirectionArrow WRITE setDirectionArrow)
    Q_PROPERTY(QMarginsF margins READ getMargins WRITE setMargins)
    Q_PROPERTY(QBrush faceBrush READ getFaceBrush WRITE setFaceBrush)
    Q_PROPERTY(QColor scaleColor READ getScaleColor WRITE setScaleColor)
    Q_PROPERTY(QColor frameBorderColor READ getFrameBorderColor WRITE setFrameBorderColor)
    Q_PROPERTY(QColor frameInsideColor READ getFrameInsideColor WRITE setFrameInsideColor)
    Q_PROPERTY(qreal beginningFrameDegree READ getBeginningFrameDegree WRITE setBeginningFrameDegree)
    Q_PROPERTY(qreal endingFrameDegree READ getEndingFrameDegree WRITE setEndingFrameDegree)
    Q_PROPERTY(QColor markerColor READ getMarkerColor WRITE setMarkerColor)
    Q_PROPERTY(qreal proportionMarker READ getProportionMarker WRITE setProportionMarker)
    Q_PROPERTY(qreal faceRadiusProportion READ getFaceRadiusProportion WRITE setFaceRadiusProportion)
    Q_PROPERTY(qreal frameSizeProportion READ getFrameSizeProportion WRITE setFrameSizeProportion)
public:
    AngularGauge(QWidget *parent = 0);
    ~AngularGauge();
    enum GaugeStyle {pie, arc, standart};
    enum DirectionArrow{clockwise, counterclockwise};

    qreal getValue() const;

    qreal getMinimumValue() const;
    qreal getMaximumValue() const;

    bool scaleIsEnabled() const;
    void setScaleIsEnabled(bool scaleIsEnabled);

    int getNumberBigScaleDivisions() const;
    void setNumberBigScaleDivisions(int numberBigScaleDivisions);

    int getNumberSmallScaleDivisions() const;
    void setNumberSmallScaleDivisions(int numberSmallScaleDivisions);

    qreal getBeginningScaleDegree() const;
    void setBeginningScaleDegree(const qreal &beginningScaleDegree);

    qreal getEndingScaleDegree() const;
    void setEndingScaleDegree(const qreal &endingScaleDegree);

    qreal getProportionBigScale() const;
    void setProportionBigScale(const qreal &proportionBigScale);

    qreal getProportionSmallScale() const;
    void setProportionSmallScale(const qreal &proportionSmallScale);

    qreal getProportionScaleRange() const;
    void setProportionScaleRange(const qreal &proportionScaleRange);

    GaugeStyle getGaugeStyle() const;
    void setGaugeStyle(const GaugeStyle &gaugeStyle);

    DirectionArrow getDirectionArrow() const;
    void setDirectionArrow(const DirectionArrow &directionArrow);

    QMarginsF getMargins() const;
    void setMargins(const QMarginsF &margins);

    QBrush getFaceBrush() const;
    void setFaceBrush(const QBrush &faceBrush);

    QColor getScaleColor() const;
    void setScaleColor(const QColor &scaleColor);

    QColor getFrameBorderColor() const;
    void setFrameBorderColor(const QColor &frameBorderColor);

    QColor getFrameInsideColor() const;
    void setFrameInsideColor(const QColor &frameInsideColor);

    qreal getBeginningFrameDegree() const;
    void setBeginningFrameDegree(const qreal &beginningFrameDegree);

    qreal getEndingFrameDegree() const;
    void setEndingFrameDegree(const qreal &endingFrameDegree);

    QColor getMarkerColor() const;
    void setMarkerColor(const QColor &markerColor);

    qreal getProportionMarker() const;
    void setProportionMarker(const qreal &proportionMarker);

    qreal getProportionSmallCircle() const;
    void setProportionSmallCircle(const qreal &proportionSmallCircle);

    qreal getFaceRadiusProportion() const;
    void setFaceRadiusProportion(const qreal &faceRadiusProportion);

    qreal getFrameSizeProportion() const;
    void setFrameSizeProportion(const qreal &frameSizeProportion);

    void addScaleRange(const ScaleRange &range);
    void clearScaleRangesList();
public slots:
    void setValue(qreal value);
    void setMinimumValue(qreal value);
    void setMaximumValue(qreal value);
protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void resizeEvent(QResizeEvent *);
    QSize sizeHint() const;
signals:
    void valueChanged(qreal value);
private:
    //изобразить "лицо" индикатора
    void drawFace(QPainter *painter);
    void drawFrame(QPainter *painter);
    void drawScaleRanges(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawNumebrs(QPainter *painter);
    void drawMarker(QPainter *painter);
    void drawText(QPainter *painter, const QPointF &point, const QString &string);

    qreal valueToDegree(qreal value);
    bool checkInRange(qreal value);

    //вычислить область в которой будет изображаться индикатор
    void computePaintArea();

    void updateFrame();
    void updateMarker();

    int computeFaceRadius();
    int computeFrameWidth();

    //значения индикатора
    qreal m_value;
    qreal m_minimumValue;
    qreal m_maximumValue;

    //свойства шкал
    bool m_scaleIsEnabled;
    int m_numberBigScaleDivisions;
    int m_numberSmallScaleDivisions;
    qreal m_beginningScaleDegree;
    qreal m_endingScaleDegree;
    qreal m_proportionBigScale;
    qreal m_proportionSmallScale;

    QList<ScaleRange> m_scaleRanges;
    qreal m_proportionScaleRange;

    //стили элементов
    GaugeStyle m_gaugeStyle;
    DirectionArrow m_directionArrow;

    //свойства области отображения
    QRect m_paintArea;
    QMarginsF m_margins;

    //свойства рамки
    QBrush m_faceBrush;
    QColor m_scaleColor;
    QColor m_frameBorderColor;
    QColor m_frameInsideColor;
    qreal m_beginningFrameDegree;
    qreal m_endingFrameDegree;
    QPainterPath m_frame;

    //свойства маркера
    QColor m_markerColor;
    qreal m_proportionMarker;
    QPainterPath m_marker;


    //пропорции радиусов от ширины области рисования
    qreal m_proportionSmallCircle;
    qreal m_faceRadiusProportion;
    qreal m_frameSizeProportion;

};

#endif // ANGULARGAUGE_H
