#include <iostream>

using std::cout;

/// 流体の種類とIDを定義
enum class FLUID {
    GAS,
    LIQUID
};
/*
int _GAS = 100;     // 気体
int _LIQUID = 110;  // 液体
*/

/// 境界条件の種類とIDを定義
enum class BC {
    PFIX_BC,     // 圧力固定の境界条件
    VFIX_BC,     // 流速固定の境界条件
    WALL_BC,     // 壁面境界の境界条件
    ON_WALL_BC,  // 境界条件
    ISOLATED_BC, // 孤立壁の境界条件
};
/*
int _PFIX_BC = 200;     // 圧力固定の境界条件
int _VFIX_BC = 210;     // 流速固定の境界条件
int _WALL_BC = 220;     // 壁面境界の境界条件
int _ON_WALL_BC = 230;  // 境界条件
int _ISOLATED_BC = 240; // 孤立壁の境界条件
*/


/// プログラム検証
int main(void) {
    FLUID i = FLUID::LIQUID;
    std::cout << static_cast<int>(i) << std::endl;
}