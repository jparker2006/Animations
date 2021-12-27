#ifndef RAIN_H
#define RAIN_H

#include <QObject>
#include <QLineF>
#include <QRandomGenerator>
#include <QColor>

class Rain {
public:
    Rain();
    void descend();
    QLineF getRainLine();
    void construct();
    float map(float num, float min1, float max1, float min2, float max2);
    float calculateWidth();
    QColor getColor();
private:
    float fx;
    float fy;
    float fz;
    float fySpeed;
    float fLength;
    QRandomGenerator *rand = new QRandomGenerator;
    QColor c_Color;
};

#endif // RAIN_H
