#ifndef TEST_FIELD_HPP
#define TEST_FIELD_HPP

#include <iostream>
#include <vector>

using std::vector;

extern int XMAX;  // X方向の最大値
extern int YMAX;  // Y方向の最大値
extern int ZMAX;  // Z方向の最大値

/// 流体の種類とIDを定義
enum class FLUID {
    GAS,
    LIQUID
};

/// 境界条件の種類とIDを定義
enum class BC {
    PFIX_BC,     // 圧力固定の境界条件
    VFIX_BC,     // 流速固定の境界条件
    WALL_BC,     // 壁面境界の境界条件
    ON_WALL_BC,  // 境界条件
    ISOLATED_BC, // 孤立壁の境界条件
};

/// 流体の物理的特性を定義するクラス
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
    void set_properties(double rho, double mu, double k = 1.0, double cp = 2.0, FLUID type, int test = 0);
    vector<double> get_properties(int test = 0);
    ~properties_of_fluid();
};



#endif // TEST_FIELD_HPP