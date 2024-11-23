#pragma once
#include <cstdint>
#include <string>

inline uint64_t ROL8(uint64_t value, uint8_t shift)
{
    return (value << shift) | (value >> (64 - shift));
}

// disassembly of the function (its messy)
uint64_t __hash(uint64_t* a1)
{
    unsigned __int64 v1; // rdi
    uint64_t* v2; // r8
    unsigned __int64 v3; // r11
    unsigned __int64 v4; // rax
    unsigned __int64 v5; // r15
    unsigned __int64 v6; // r13
    unsigned __int64 v7; // r12
    unsigned __int64 v8; // rbp
    __int64 v9; // r14
    __int64 v10; // rbx
    __int64 v11; // rdi
    __int64 v12; // rsi
    unsigned __int64 v13; // rsi
    unsigned __int64 v14; // rsi
    unsigned __int64 v15; // r11
    unsigned __int64 v16; // rbx
    __int64 v17; // rdi
    unsigned __int64 v18; // rax
    __int64 v19; // rsi
    unsigned __int64 v20; // rax
    __int64 v21; // rax
    unsigned __int64 v22; // r10
    __int64 v23; // rax

    v2 = a1;
    if (a1[3] >= 0x10)
        v2 = (uint64_t*)*a1;

    if (!v2)
    {
        v1 = 0x27D4EB2F165667C5;
        return (0x165667B19E3779F9
            * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) ^ ((0x165667B19E3779F9 * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) >> 32);
    }

    v3 = a1[2];
    if (v3 < 0x20)
    {
        v13 = 0x27D4EB2F165667C5;
    }
    else
    {
        v4 = (unsigned __int64)v2 + v3 - 31;
        v5 = 0x61C8864E7A143579;
        v6 = 0x60EA27EEADC0B5D6;
        v7 = 0;
        v8 = 0xC2B2AE3D27D4EB4Fu;
        do {
            v9 = ROL8(v6 - 0x3D4D51C2D82B14B1 * *v2, 31);
            v6 = 0x9E3779B185EBCA87u * v9;
            v10 = ROL8(v8 - 0x3D4D51C2D82B14B1 * v2[1], 31);
            v11 = ROL8(v7 - 0x3D4D51C2D82B14B1 * v2[2], 31);
            v8 = 0x9E3779B185EBCA87u * v10;
            v7 = 0x9E3779B185EBCA87u * v11;
            v12 = ROL8(v5 - 0x3D4D51C2D82B14B1 * v2[3], 31);
            v5 = 0x9E3779B185EBCA87u * v12;
            v2 += 4;
        } while ((unsigned __int64)v2 < v4);

        v1 = 0x85EBCA77C2B2AE63u
            - 0x61C8864E7A143579
            * ((0x85EBCA77C2B2AE63u
                - 0x61C8864E7A143579
                * ((0x85EBCA77C2B2AE63u
                    - 0x61C8864E7A143579
                    * ((ROL8(v6, 1) + ROL8(v8, 7) + ROL8(v7, 12) + ROL8(v5, 18)) ^ (0x9E3779B185EBCA87u
                        * ROL8(
                            0xDEF35B010F796CA9u * v9,
                            31)))) ^ (0x9E3779B185EBCA87u * ROL8(0xDEF35B010F796CA9u * v10, 31)))) ^ (0x9E3779B185EBCA87u * ROL8(0xDEF35B010F796CA9u * v11, 31)));
        v13 = 0x9E3779B185EBCA87u * (v1 ^ (0x9E3779B185EBCA87u * ROL8(0xDEF35B010F796CA9u * v12, 31)))
            - 0x7A1435883D4D519D;
    }

    v14 = v3 + v13;
    v15 = a1[2] & 0x1F;
    if (v15 < 8)
        goto LABEL_16;
    v16 = v15 - 8;

    if (((v15 - 8) & 8) != 0)
    {
        if (v16 < 8)
            goto LABEL_17;
        goto LABEL_15;
    }

    v17 = ROL8(0xC2B2AE3D27D4EB4Fu * *v2++, 31);
    v1 = 0x85EBCA77C2B2AE63u - 0x61C8864E7A143579 * ROL8(v14 ^ (0x9E3779B185EBCA87u * v17), 27);
    v15 -= 8;
    v14 = v1;
    if (v16 >= 8)
    {
        do
        {
        LABEL_15:
            v18 = 0x85EBCA77C2B2AE63u
                - 0x61C8864E7A143579
                * ROL8(v14 ^ (0x9E3779B185EBCA87u * ROL8(0xC2B2AE3D27D4EB4Fu * *v2, 31)), 27);
            v19 = ROL8(0xC2B2AE3D27D4EB4Fu * v2[1], 31);
            v2 += 2;
            v14 = 0x85EBCA77C2B2AE63u - 0x61C8864E7A143579 * ROL8(v18 ^ (0x9E3779B185EBCA87u * v19), 27);
            v15 -= 16;
        } while (v15 > 7);
    LABEL_16:
        v1 = v14;
        v16 = v15;
    }

LABEL_17:
    if (v16 >= 4)
    {
        v20 = v1 ^ (0x9E3779B185EBCA87u * *(unsigned int*)v2);
        v2 = (uint64_t*)((char*)v2 + 4);
        v16 -= 4;
        v1 = 0x165667B19E3779F9 - 0x3D4D51C2D82B14B1 * ROL8(v20, 23);
        if (!v16)
            return (0x165667B19E3779F9
                * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) ^ ((0x165667B19E3779F9 * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) >> 32);
    }
    else if (!v16)
    {
        return (0x165667B19E3779F9
            * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) ^ ((0x165667B19E3779F9 * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) >> 32);
    }

    if ((v16 & 3) == 0)
    {
        v22 = v16;
        if (v16 < 4)
            return (0x165667B19E3779F9
                * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) ^ ((0x165667B19E3779F9 * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) >> 32);
        goto LABEL_27;
    }
    v21 = 0;
    do
        v1 = 0x9E3779B185EBCA87u * ROL8(v1 ^ (0x27D4EB2F165667C5 * *((unsigned __int8*)v2 + v21++)), 11);
    while ((v16 & 3) != v21);
    v22 = v16 - v21;
    v2 = (uint64_t*)((char*)v2 + v21);
    if (v16 >= 4)
    {
    LABEL_27:
        v23 = 0;
        do
        {
            v1 = 0x9E3779B185EBCA87u
                * ROL8(
                    (0x9E3779B185EBCA87u
                        * ROL8(
                            (0x9E3779B185EBCA87u
                                * ROL8(
                                    (0x9E3779B185EBCA87u * ROL8(v1 ^ (0x27D4EB2F165667C5 * *((unsigned __int8*)v2 + v23)), 11)) ^ (0x27D4EB2F165667C5 * *((unsigned __int8*)v2 + v23 + 1)),
                                    11)) ^ (0x27D4EB2F165667C5 * *((unsigned __int8*)v2 + v23 + 2)),
                            11)) ^ (0x27D4EB2F165667C5 * *((unsigned __int8*)v2 + v23 + 3)),
                    11);
            v23 += 4;
        } while (v22 != v23);
    }
    return (0x165667B19E3779F9
        * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) ^ ((0x165667B19E3779F9 * ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) ^ ((0xC2B2AE3D27D4EB4Fu * (v1 ^ (v1 >> 33))) >> 29))) >> 32);
}

uint64_t hash(std::string input) {
    uint64_t* data = new uint64_t[4];
    data[0] = reinterpret_cast<uint64_t>(const_cast<char*>(input.c_str()));
    data[1] = 0;
    data[2] = input.length();

    return __hash(data);
}