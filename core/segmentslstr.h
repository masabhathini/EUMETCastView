#ifndef SEGMENTSLSTR_H
#define SEGMENTSLSTR_H

#include <QObject>
#include <segment.h>


class SegmentSLSTR : public Segment
{
    Q_OBJECT

public:
    explicit SegmentSLSTR(QFileInfo fileinfo, SatelliteList *satl = 0, QObject *parent = 0);
    Segment *ReadSegmentInMemory();
    void ComposeSegmentImage(int histogrammethod);
    int getEarthViewsPerScanline() { return this->earth_views_per_scanline; }
    void setBandandColorandView(QList<bool> band, QList<int> color, QList<bool> invert, eSLSTRImageView slstrview);

    QScopedArrayPointer<int> latitude;
    QScopedArrayPointer<int> longitude;

private:
    void initializeMemory();
    void getDatasetNameFromBand(eSLSTRImageView view, QString *radiancedataset, QString *radiancevariable, QString *geodeticdataset, QString *latitude, QString *longitude);
    void getDatasetNameFromColor(eSLSTRImageView view, int colorindex, QString *radiancedataset, QString *radiancevariable, QString *geodeticdataset, QString *latitude, QString *longitude);
    void RenderSegmentlineInTextureSLSTR( int nbrLine, QRgb *row );

    bool invertthissegment[3];
    eSLSTRImageView slstrview;

};

#endif // SEGMENTSLSTR_H
