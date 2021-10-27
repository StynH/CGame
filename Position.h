#pragma once
#include <stdint.h>

//##############################
//STRUCTS
//##############################
typedef struct Vector2D
{
	int32_t x;
	int32_t y;
} Vector2D;

typedef struct Vector2Df
{
	float x;
	float y;
} Vector2Df;

typedef struct Vector2Dd
{
	double x;
	double y;
} Vector2Dd;

typedef struct Vector2Du
{
	unsigned char x;
	unsigned char y;
} Vector2Du;

typedef struct Vector3D
{
	int32_t x;
	int32_t y;
	int32_t z;
} Vector3D;

typedef struct Vector3Df
{
	float x;
	float y;
	float z;
} Vector3Df;

typedef struct Vector3Dd
{
	double x;
	double y;
	double z;
} Vector3Dd;

typedef struct Vector3Du
{
	unsigned char x;
	unsigned char y;
	unsigned char z;
} Vector3Du;

typedef struct Rectangle
{
	int32_t x;
	int32_t y;
	int32_t width;
	int32_t height;
} Rectangle;

typedef struct RectangleF
{
	float x;
	float y;
	float width;
	float height;
} RectangleF;

typedef struct Rotation
{
	float angle;
	float increase;
} Rotation;