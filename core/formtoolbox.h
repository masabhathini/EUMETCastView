#ifndef FORMTOOLBOX_H
#define FORMTOOLBOX_H

#include <QWidget>
#include "formimage.h"
#include "formmapcyl.h"
#include "formgeostationary.h"

#define TAB_AVHRR 0
#define TAB_VIIRS 1
#define TAB_GEOSTATIONARY 2
#define TAB_PROJECTION 3

#define TAB_LLC 0
#define TAB_GVP 1
#define TAB_GS  2

namespace Ui {
    class FormToolbox;
}

class FormImage;
class FormGeostationary;

class FormToolbox : public QWidget
{
    Q_OBJECT

public:
    explicit FormToolbox(QWidget *parent = 0, FormImage *p_formimage = 0, FormGeostationary *p_formgeostationary = 0, AVHRRSatellite *seglist = 0);
    int getTabWidgetIndex();
    QList<bool> getVIIRSBandList();
    QList<int> getVIIRSColorList();
    QList<bool> getVIIRSInvertList();
    void setTabWidgetIndex(int index);
    void setTabWidgetVIIRSIndex(int index);
    void writeInfoToAVHRR(QString info);
    void writeInfoToVIIRS(QString info);
    void writeInfoToGeo(QString info);
    void createFilenamestring(QString sat, QString d, QVector<QString> spectrum);
    QString returnFilenamestring() { return filenamecreated; }
    bool comboColVIIRSOK();
    bool comboColGeoOK();
    bool GridOnProjLCC();
    bool GridOnProjGVP();
    bool GridOnProjSG();


    ~FormToolbox();

private:
    Ui::FormToolbox *ui;
    FormImage *formimage;
    FormGeostationary *formgeostationary;

    void setupChannelCombo();
    void setInverseCheckBoxes();
    void setParameters();
    void onButtonChannel(QString channel, bool bInverse);
    void onButtonColorHRV(QString type);
    bool eventFilter(QObject *target, QEvent *event);
    int searchResolution(int mapwidth, int mapheight);
    void setPOIsettings();
    void setLCCParameters(int strlindex);
    void setGVPParameters(int strlindex);
    void setSGParameters(int strlindex);

    AVHRRSatellite *segs;

    QVector<QString> spectrumvector;
    QVector<bool> inversevector;
    SegmentListGeostationary::eGeoSatellite whichgeo;
    QStringList rowchosen;
    QString filenamecreated;
    QVector<int> resolutionX;
    QVector<int> resolutionY;
    int currentAVHRRimage; // from 1 to 6 , 6 color image

public slots:
    void setChannelComboBoxes();
    void setChannelIndex();
    void geostationarysegmentsChosen(SegmentListGeostationary::eGeoSatellite geo, QStringList tex);
    void setToolboxButtons(bool state);

signals:
    void getmeteosatchannel(QString, QVector<QString>, QVector<bool>);
    void overlaycorrection(int,int);
    void switchstackedwidget(int);
    void emitShowVIIRSImage();
    void screenupdateprojection();


private slots:
    void on_btnCol_clicked();
    void on_btnCh1_clicked();
    void on_btnCh2_clicked();
    void on_btnCh3_clicked();
    void on_btnCh4_clicked();
    void on_btnCh5_clicked();

    void setChannelInverse();
    void setMeteosatGamma();
    void setMeteosatGamma(double gammaval);
    void setValueProgressBar(int val);


    void on_btnGeoColor_clicked();
    void on_btnCLAHEMeteosat_clicked();
    void on_btnExpandImage_clicked();
    void on_btnRotate180_clicked();
    void on_btnOverlayMeteosat_clicked();
    void on_btnCLAHEavhhr_clicked();
    void on_btnVIS006_clicked();
    void on_btnVIS008_clicked();
    void on_btnIR016_clicked();
    void on_btnIR039_clicked();
    void on_btnWV062_clicked();
    void on_btnWV073_clicked();
    void on_btnIR087_clicked();
    void on_btnIR097_clicked();
    void on_btnIR108_clicked();
    void on_btnIR120_clicked();
    void on_btnIR134_clicked();
    void on_btnTextureMet_clicked();
    void on_btnTextureAVHRR_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_spbNorth_valueChanged(int arg1);
    void on_spbWest_valueChanged(int arg1);
    void on_spbEast_valueChanged(int arg1);
    void on_spbSouth_valueChanged(int arg1);
    void on_chkShowLambert_stateChanged(int arg1);
    void on_btnCreateLambert_clicked();
    void on_spbLCCMapWidth_valueChanged(int arg1);
    void on_spbLCCMapHeight_valueChanged(int arg1);
    void on_spbGVPMapWidth_valueChanged(int arg1);
    void on_spbGVPMapHeight_valueChanged(int arg1);
    void on_spbSGMapWidth_valueChanged(int arg1);
    void on_spbSGMapHeight_valueChanged(int arg1);
    void on_btnCreatePerspective_clicked();
    void on_spbGVPlat_valueChanged(double arg1);
    void on_spbGVPlon_valueChanged(double arg1);
    void on_spbGVPheight_valueChanged(int arg1);
    void on_spbGVPscale_valueChanged(double arg1);
    void on_btnOverlayProjectionGVP_clicked();
    void on_btnOverlayProjectionLCC_clicked();
    void on_chkShowPerspective_stateChanged(int arg1);
    void on_toolBox_currentChanged(int index);
    void on_spbParallel1_valueChanged(int arg1);
    void on_spbParallel2_valueChanged(int arg1);
    void on_spbCentral_valueChanged(int arg1);
    void on_spbLatOrigin_valueChanged(int arg1);
    void on_spbScaleX_valueChanged(double arg1);
    void on_spbScaleY_valueChanged(double arg1);
    void on_btnHRV_clicked();
    void on_btnGVPClearMap_clicked();
    void on_btnLCCClearMap_clicked();

    void on_btnLCCMapNorth_clicked();
    void on_btnLCCMapSouth_clicked();
    void on_btnLCCMapWest_clicked();
    void on_btnLCCMapEast_clicked();
//    void on_scbLCCMapUpDown_valueChanged(int value);
//    void on_scbLCCMapLeftRight_valueChanged(int value);
    void on_spbSGlat_valueChanged(double arg1);
    void on_spbSGlon_valueChanged(double arg1);
    void on_spbSGScale_valueChanged(double arg1);
    void on_btnCreateStereo_clicked();
    void on_btnGVPHome_clicked();
    void on_btnSGHome_clicked();

    void on_spbSGPanHorizon_valueChanged(int arg1);
    void on_spbSGPanVert_valueChanged(int arg1);
    void on_spbSGRadius_valueChanged(double arg1);
    void on_btnSGClearMap_clicked();
    void on_btnOverlayProjectionSG_clicked();
    void on_spbLCCCorrX_valueChanged(int arg1);
    void on_spbLCCCorrY_valueChanged(int arg1);
    void on_btnSetTrueColors_clicked();
    void on_btnSetNaturalColors_clicked();
    void on_btnMakeVIIRSImage_clicked();
    void on_rbtnAColor_clicked();
    void on_rbtnACh1_clicked();
    void on_rbtnACh2_clicked();
    void on_rbtnACh3_clicked();
    void on_rbtnACh4_clicked();
    void on_rbtnACh5_clicked();
    void on_btnTextureVIIRS_clicked();
    void on_sliCLAHE_sliderMoved(int position);

    void on_cbProjResolutions_currentIndexChanged(int index);

    void on_sbCentreBand_valueChanged(int value);
    void on_spbDnbWindow_valueChanged(int arg1);
    void on_comboPOI_currentIndexChanged(int index);
    void on_chkLCCGridOnProj_clicked();
    void on_chkGVPGridOnProj_clicked();
    void on_chkSGGridOnProj_clicked();
    void on_btnAddPOI_clicked();
};

#endif // FORMTOOLBOX_H


