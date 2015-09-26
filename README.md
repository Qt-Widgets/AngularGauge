# Angular Gauge for Qt

AngularGauge - это класс кругового индикатора.
![ScreenShot](http://imageshack.com/a/img661/2320/rHUg2q.png)
===================
## Открытые типы
```c++
    enum GaugeStyle {pie, arc, standart};
    enum DirectionArrow{clockwise, counterclockwise};
```
===================
## Свойства
 - value : qreal
 - minimumValue : qreal
 - maximumValue : qreal
 - scaleIsEnabled : bool
 - numberBigScaleDivisions : int
 - numberSmallScaleDivisions : int
 - beginningScaleDegree : qreal
 - endingScaleDegree : qreal
 - proportionBigScale : qreal
 - proportionSmallScale : qreal
 - proportionScaleRange : qreal
 - gaugeStyle : GaugeStyle
 - directionArrow : DirectionArrow
 - margins : QMargins
 - faceBrush : QBrush
 - scaleColor : QColor
 - frameBorderColor : QColor
 - frameInsideColor  : QColor
 - beginningFrameDegree : qreal
 - endingFrameDegree : qreal
 - markerColor : QColor
 - proportionMarker  : qreal
 - faceRadiusProportion : qreal
 - frameSizeProportion : qreal

===================

## Открытые функции
```c++
    AngularGauge(QWidget *parent = 0);
    ~AngularGauge();

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
```

===================

## Открытые слоты
```c++
    void setValue(qreal value);
    void setMinimumValue(qreal value);
    void setMaximumValue(qreal value);
```

===================

## Сигналы
```c++
    void valueChanged(qreal value);
```

===================

## Описание типов-членов

    enum GaugeStyle
Это перечисление описывает форму индикатора.

Константа | Описание
--------  | ---
pie       | Индикатор в форме пирога
arc       | Индикатор в форме усеченного круга
standart  | Индикатор в форме круга

![ScreenShot](http://imageshack.com/a/img901/2886/43V1h3.png) |![ScreenShot](http://imageshack.com/a/img673/8146/VJuYQD.png) | ![ScreenShot](http://imageshack.com/a/img911/6905/TzhmIH.png)
------------- | ------------- | -------------
GaugeStyle::pie  | GaugeStyle::arc   | GaugeStyle::standart

===================

    enum DirectionArrow
Это перечисление описывает направление вращения стрелки

Константа | Описание
--------  | ---
clockwise       | По часовой
counterclockwise     | Против часовой

![ScreenShot](http://imageshack.com/a/img911/6905/TzhmIH.png) | ![ScreenShot](http://imagizer.imageshack.us/a/img673/2526/UbDBUG.png)
--------  | ---
По часовой| Против часовой

===================

## Описание свойств
### value
Это свойство содержит значение индикатора.
#### Функции доступа:
* qreal getValue() const
* void setValue(qreal value)

===================

### minimumValue
Это свойство содержит минимальное значение индикатора.
#### Функции доступа:
* qreal getMinimumValue() const
* void setMinimumValue(qreal value)

===================

### maximumValue
Это свойство содержит максимальное значение индикатора.
#### Функции доступа:
* qreal getMaximumValue() const
* void setMaximumValue(qreal value)

===================

### scaleIsEnabled
Это свойство показывает отображать ли шкалу.
#### Функции доступа:
* qreal scaleIsEnabled() const
* void setScaleIsEnabled(bool scaleIsEnabled)

===================

### scaleIsEnabled
Это свойство показывает отображать ли шкалу.
#### Функции доступа:
* qreal scaleIsEnabled() const
* void setScaleIsEnabled(bool scaleIsEnabled)

===================

### numberBigScaleDivisions
Это свойство показывает число больших делений в шкале.
#### Функции доступа:
* int getNumberBigScaleDivisions() const
* void setNumberBigScaleDivisions(int numberBigScaleDivisions)

===================

### numberBigScaleDivisions
Это свойство показывает число маленьких делений в шкале.
#### Функции доступа:
* int getNumberSmallScaleDivisions() const
* void setNumberSmallScaleDivisions(int numberSmallScaleDivisions)

===================

### beginningScaleDegree
Это свойство содержит положение начала шкалы в градусах.
#### Функции доступа:
* qreal getBeginningScaleDegree() const
* void setBeginningScaleDegree(const qreal &beginningScaleDegree)

===================

### endingScaleDegree
Это свойство содержит положение конца шкалы в градусах.
#### Функции доступа:
* qreal getEndingScaleDegree() const
* void setEndingScaleDegree(const qreal &beginningScaleDegree)

===================

### proportionBigScale
Это свойство устанавливает пропорцию длины большой шкалы от радиуса индикатора.
Оно изменается от 0 до 1.
#### Функции доступа:
* qreal getProportionBigScale() const
* void setProportionBigScale(const qreal &proportionBigScale)

===================

### proportionSmallScale
Это свойство устанавливает пропорцию длины маленькой шкалы от радиуса индикатора.
Оно изменается от 0 до 1.
#### Функции доступа:
* qreal getProportionSmallScale() const
* void setProportionSmallScale(const qreal &proportionSmallScale)

===================

### proportionScaleRange
Это свойство устанавливает пропорцию ширины выделения от радиуса индикатора.
Оно изменается от 0 до 1.
#### Функции доступа:
* qreal getProportionScaleRange() const
* void setProportionScaleRange(const qreal &proportionScaleRange)

===================

### gaugeStyle
Это свойство устанавливает стиль формы индикатора.
#### Функции доступа:
* GaugeStyle getGaugeStyle() const
* void setGaugeStyle(const GaugeStyle &gaugeStyle)

===================

### directionArrow
Это свойство содержит направление вращения стрелки.
#### Функции доступа:
* DirectionArrow getDirectionArrow() const
* void setDirectionArrow(const DirectionArrow &directionArrow)

===================

### margins
Это свойство содержит величину отступов.
#### Функции доступа:
* QMarginsF getMargins() const
* void setMargins(const QMarginsF &margins)

===================

### faceBrush
Это свойство содержит цвет заливки "лица" индикатора.
#### Функции доступа:
* QBrush getFaceBrush() const
* void setFaceBrush(const QBrush &faceBrush)

===================

### faceBrush
Это свойство содержит цвет заливки "лица" индикатора.
#### Функции доступа:
* QBrush getFaceBrush() const
* void setFaceBrush(const QBrush &faceBrush)

===================

### scaleColor
Это свойство содержит цвет шкалы индикатора.
#### Функции доступа:
* QColor getScaleColor() const
* void setScaleColor(const QColor &scaleColor)

===================

### frameBorderColor
Это свойство содержит цвет границы рамки индикатора.
#### Функции доступа:
* QColor getFrameBorderColor() const
* void setFrameBorderColor(const QColor &frameBorderColor)

===================

### frameInsideColor
Это свойство содержит цвет внутренней стороны рамки индикатора.
#### Функции доступа:
* QColor getFrameInsideColor() const
* void setFrameInsideColor(const QColor &frameInsideColor)

===================

### beginningFrameDegree
Это свойство содержит положение начала рамки в градусах.
#### Функции доступа:
* qreal getBeginningFrameDegree() const
* void setBeginningFrameDegree(const qreal &beginningFrameDegree)

===================

### endingFrameDegree
Это свойство содержит положение начала рамки в градусах.
#### Функции доступа:
* qreal getEndingFrameDegree() const
* void setEndingFrameDegree(const qreal &endingFrameDegree)

===================

### markerColor
Это свойство содержит цвет стрелки индикатора.
#### Функции доступа:
* QColor getMarkerColor() const
* void setMarkerColor(const QColor &markerColor)

===================

### proportionMarker
Это свойство устанавливает пропорцию длины стрелки от радиуса индикатора.
Оно изменается от 0 до 1.
#### Функции доступа:
* qreal getProportionMarker() const
* void setProportionMarker(const qreal &proportionMarker)

===================

### faceRadiusProportion
Это свойство устанавливает пропорцию радиуса "лица" индикатора от радиуса индикатора.
Оно изменается от 0 до 1.
Предпочтительно оно должно образовывать в сумме с frameSizeProportion 1.
#### Функции доступа:
* qreal getFaceRadiusProportion() const
* void setFaceRadiusProportion(const qreal &faceRadiusProportion)

===================

### frameSizeProportion
Это свойство устанавливает пропорцию ширины рамки индикатора от радиуса индикатора.
Оно изменается от 0 до 1.
Предпочтительно оно должно образовывать в сумме с faceRadiusProportion 1.
#### Функции доступа:
* qreal getFrameSizeProportion() const
* void setFrameSizeProportion(const qreal &frameSizeProportion)

===================

## Описание функций-членов
```c++
    AngularGauge(QWidget *parent = 0);
```
Создает новый индикатор.

===================
  
```c++
    ~AngularGauge();
```
Уничтожает индикатор.

===================

```c++
    void addScaleRange(const ScaleRange &range);
```
Добавляет выделение.

######Пример

```c++
    int beginValue = 70;       // Значение начала выделения
    int endValue = 100;        // Значение конца выделения
    QColor color(Qt::darkRed); // Цвет выделения
    angularGauge->addScaleRange(ScaleRange(beginValue, endValue, color));
```

![ScreenShot](http://imageshack.com/a/img537/1966/cQX7kY.png)

===================

```c++
    void clearScaleRangesList();
```
Очищает список выделений.

===================

## Описание сигналов
```c++
    void valueChanged(qreal value);
```
Этот сигнал посылается, когда изменяется значение индикатора.

===================

