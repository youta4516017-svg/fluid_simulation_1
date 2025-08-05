#ifndef TEST_FIELD_HPP
#define TEST_FIELD_HPP

#include <iostream>
#include <vector>

using std::vector;

extern int XMAX;  // X方向の最大値
extern int YMAX;  // Y方向の最大値
extern int ZMAX;  // Z方向の最大値
extern int DIM;   // 次元（2D or 3D）
extern int NMAX;  // 計算領域の要素の最大値
extern double dt; // 時間刻み
extern double dx; // X方向の格子間隔
extern double dy; // Y方向の格子間隔
extern double dz; // Z方向の格子間隔

extern vector<double> P; // 圧力
extern vector<double> U; // x方向の速度のベクトル
extern vector<double> V; // y方向の速度のベクトル
extern vector<double> W; // z方向の速度のベクトル
extern vector<double> T; // 温度
extern vector<double> du; // x方向の速度の変化量
extern vector<double> dv; // y方向の速度の変化量
extern vector<double> dw; // z方向の速度の変化量

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

/// 流体の物性を定義するクラス
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

/// 計算領域を定義するクラス
class make_field {
private:
    int X;
    int Y;
    int Z;
    int dimension; // 2D or 3D
    int nmax;
public:
    make_field();
    void set_field(int dim = 2, int test = 0);
    vector<int> get_field(int test = 0);
    ~make_field();
};

/// 解析条件を設定するクラス
class analysis_condition
{
private:
    double time_step; // 時間刻み
    double grid_spacing_x; // X方向の格子間隔
    double grid_spacing_y; // Y方向の格子間隔
    double grid_spacing_z; // Z方向の格子間隔

public:
    analysis_condition(/* args */);
    void set_condition(int test = 0);
    vector<double> get_condition(int test = 0);
    void check_CFLcondition(int test = 0);
    ~analysis_condition();
};



/// 一次元配列の番号から格子の位置を計算する関数群
class calc_index
{
private:
    int index; // 一次元配列のインデックス
public:
    calc_index(/* args */);
    vector<int> get_index(int idx);
    int reverse_index(int i, int j);
    int reverse_index(int i, int j, int k);
    ~calc_index();
};



#endif // TEST_FIELD_HPP