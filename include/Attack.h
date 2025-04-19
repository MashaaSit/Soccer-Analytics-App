#ifndef ATTACK_H
#define ATTACK_H
#include "Pass.h"
#include <QPoint>
#include <QVector>
#include <tuple>
#include <utility>

#define M_PI 3.14159265358979323846

using passes_container = QVector<Pass>;

class Attack {
public:
    Attack(): teamId(0), passes({}) {
    }

    Attack(const int team_id, const passes_container &_passes): teamId(team_id), passes(_passes) {
    }

    int getTeamId() const { return teamId; }
    passes_container getPasses() const { return passes; }
    void setTeam(int id) { teamId = id; }
    void setPasses(const passes_container &_passes) { passes = _passes; }
    void clear() {
        teamId=0;
        passes={};
    }
private:
    int teamId;

    passes_container passes;
};


#endif //ATTACK_H
