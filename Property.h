#pragma once

namespace OpenglToolKit
{
    struct Property{
        enum DataType{
            INT = 0, FLOAT = 1, FLOAT2 = 2, FLOAT3 = 3, FLOAT4 = 4
        };
        DataType Type;
        int int_data;
        float float_data;
        float float2_data[2];
        float float3_data[3];
        float float4_data[4];

        Property(int value){
            Type = INT;
            int_data = value;
        }
        Property(float value){
            Type = FLOAT;
            float_data = value;
        }
        Property(float value1, float value2){
            Type = FLOAT2;
            float2_data[0] = value1;
            float2_data[1] = value2;
        }
        Property(float value1, float value2, float value3){
            Type = FLOAT3;
            float3_data[0] = value1;
            float3_data[1] = value2;
            float3_data[2] = value3;
        }
        Property(float value1, float value2, float value3, float value4){
            Type = FLOAT4;
            float4_data[0] = value1;
            float4_data[1] = value2;
            float4_data[2] = value3;
            float4_data[3] = value4;
        }
    };
}