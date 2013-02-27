#ifndef FIELDLINE_H
#define FIELDLINE_H

#include "Tools/Math/LSFittedLine.h"
#include "Tools/Math/General.h"

#include "Vision/basicvisiontypes.h"
#include "Vision/VisionTypes/VisionFieldObjects/visionfieldobject.h"

class FieldLine : public VisionFieldObject
{
public:
    FieldLine(const LSFittedLine& screen_line, const LSFittedLine& ground_line);
    FieldLine(const Vector2<GroundPoint>& end_points);

    void set(const LSFittedLine& screen_line, const LSFittedLine& ground_line);
    void set(const Vector2<GroundPoint>& end_points);

    Line getScreenLineEquation() const {return m_screen_line;}
    Line getGroundLineEquation() const {return m_ground_line;}
    Vector2<GroundPoint> getEndPoints() const {return m_end_points;}
    
    //! @brief Stream output for labelling purposes
    void printLabel(ostream& out) const {out << VFOName(FIELDLINE) << " " << getShortLabel();}
    //! @brief Brief stream output for labelling purposes
    Vector2<double> getShortLabel() const {return Vector2<double>(m_screen_line.getRho(), m_screen_line.getPhi());}

    //dummy until localisation can handle lines
    bool addToExternalFieldObjects(FieldObjects *fieldobjects, float timestamp) const {return false && fieldobjects && timestamp==0;}

    //! @brief Calculation of error for optimisation - assumed measured = (rho, phi)
    double findError(const Vector2<double>& measured) const;
    double findError(const FieldLine& measured) const;

    //! @brief output stream operator
    friend ostream& operator<< (ostream& output, const FieldLine& l);
    //! @brief output stream operator for a vector of FieldLines
    friend ostream& operator<< (ostream& output, const vector<FieldLine>& v);

private:
    Line m_screen_line,
         m_ground_line;
    Vector2<GroundPoint> m_end_points;
};

#endif // FIELDLINE_H
