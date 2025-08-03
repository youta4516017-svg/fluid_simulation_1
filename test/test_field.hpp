#ifndef TEST_FIELD_HPP
#define TEST_FIELD_HPP

#include <iostream>
#include <vector>

using std::vector;

extern int XMAX;  // X方向の最大値
extern int YMAX;  // Y方向の最大値
extern int ZMAX;  // Z方向の最大値

/// 流体の種類とIDを定義
typedef enum {
    GAS,
    LIQUID
} FLUID;

/// 境界条件の種類とIDを定義
typedef enum {
    PFIX_BC,     // 圧力固定の境界条件
    VFIX_BC,     // 流速固定の境界条件
    WALL_BC,     // 壁面境界の境界条件
    ON_WALL_BC,  // 境界条件
    ISOLATED_BC, // 孤立壁の境界条件
} BoundaryCondition;

/// 計算領域を定義するクラス
class properties_of_fluid
{
private:
    double density;  // 密度
    double viscosity; // 動粘性係数
    double thermal_conductivity; // 熱伝導率
    double specific_heat; // 比熱
    FLUID fluid_type; // 流体の種類

public:
    //int test; // テスト用のフラグ
    properties_of_fluid(/* args */);
    void set_properties(double rho, double mu, double k, double cp, FLUID type = GAS, int test = 0);
    vector<double> get_properties(int test = 0);
    ~properties_of_fluid();
};

class make_field {
private:
    int X;
    int Y;
    int Z; 
public:
    make_field(/* args */);
    void set_field(int dimension = 2, int test = 0);
    vector<double> get_field(int XMAX, int YMAX, int ZMAX, int test = 0);
    ~make_field();
};



#endif // TEST_FIELD_HPP