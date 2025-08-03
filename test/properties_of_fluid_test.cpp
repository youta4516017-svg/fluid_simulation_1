// properties_of_fluid クラスの実装の中身
#include <iostream>
#include <vector>
#include "test_field.hpp"

using std::vector;

// コンストラクタ
properties_of_fluid::properties_of_fluid(){
    density = 0.0;  // 初期化
    viscosity = 0.0; // 初期化
    thermal_conductivity = 0.0; // 初期化
    specific_heat = 0.0; // 初期化
    fluid_type = GAS; // 初期化
    //std::cout << "call properties of property" << std::endl;  // デバッグ用のメッセージ
}

/// @brief 流体の物理的特性を設定する関数
void properties_of_fluid::set_properties(double rho, double mu, double k, double cp, FLUID type, int test){
    
    if (1 == test)  // test が 1 の場合は、テスト用の値を設定
    {
        density = 1000.0;  // 密度の仮の値
        viscosity = 0.001; // 動粘性係数の仮の値
        thermal_conductivity = 0.6; // 熱伝導率の仮の値
        specific_heat = 10; // 比熱の仮の値
        fluid_type = FLUID::LIQUID; // 流体の種類を液体に設定
    } else {
        density = rho;  // 密度
        viscosity = mu; // 動粘性係数
        thermal_conductivity = k; // 熱伝導率
        specific_heat = cp; // 比熱
        fluid_type = type; // 流体の種類を液体に設定
    }
    
};

vector<double> properties_of_fluid::get_properties(int test){
    vector<double> properties(4);
    properties[0] = density;  // 密度
    properties[1] = viscosity; // 動粘性係数
    properties[2] = thermal_conductivity; // 熱伝導率
    properties[3] = specific_heat; // 比熱
    //properties[4] = static_cast<double>(fluid_type); // 流体の種類をdouble型に変換して格納

    if (1 == test)  // test が 1 の場合は、セットされた値を表示
    {
        std::cout << "Test mode: Returning properties." << std::endl;
        std::cout << properties[0] << ", " << properties[1] << ", " 
                  << properties[2] << ", " << properties[3] << ", " 
                  << static_cast<int>(fluid_type) << std::endl;
    }
    
    return properties;
}

// デコンストラクタ
properties_of_fluid::~properties_of_fluid(){
    // std::cout << "call properties of fluid destructor" << std::endl;     // デバッグ用のメッセージ
    // ここでリソースの解放などを行う
    // 特に動的メモリ割り当てを行っていないので、特に何もしない
};


// プログラム検証
int main(void) {
    //std::cout << static_cast<int>(FLUID::LIQUID) << std::endl;
    properties_of_fluid fluid;

    fluid.set_properties(1000.0, 0.001, 0.6, 10.0, FLUID::LIQUID, 1); // テストモードで流体の諸元を設定  
    vector<double> props = fluid.get_properties(1); // テストモードで呼び出し
    
    fluid.set_properties(1.10, 3.8, FLUID::GAS, 0);   // 通常モードで流体の諸元を設定
    vector<double> props_normal = fluid.get_properties(1); // 通常モードが正しく機能しているかの確認

    return 0;
}