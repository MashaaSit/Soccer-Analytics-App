//
// Created by masha on 24.03.25.
//

#ifndef PASS_H
#define PASS_H
#include <QVector>
#include <QPair>

using pair_int = QPair<int, int>;
using pair_double = QPair<double, double>;

class Pass {
public:
    Pass() = default;

    Pass(const pair_int &time, const pair_double &from, const pair_double &to, const bool _is_foot,
         const bool _is_chipped): pass_time(time), point_from(from), point_to(to), is_foot(_is_foot),
                                  is_chipped(_is_chipped) {
    }

    pair_int getTime() const { return pass_time; }
    pair_double getPointFrom() const { return point_from; }
    pair_double getPointTo() const { return point_to; }
    bool getIsFoot() const { return is_foot; }
    bool getIsChipped() const { return is_chipped; }
    bool empty() { return true; }

private:
    pair_int pass_time;
    pair_double point_from;
    pair_double point_to;
    bool is_foot = false;
    bool is_chipped = false;
};


#endif //PASS_H
