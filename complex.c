#include <stdio.h>
#include <math.h>

const double PI = 3.1415926;
enum coordinate_type {RECTANGULAR, POLAR};
struct complex_struct {
    enum coordinate_type t;
    double a, b;
};

struct segment {
    struct complex_struct start;
    struct complex_struct end;
};

double trans_to_arg(double x)
{
    while (x > PI)
    {
        x = x - 2 * PI;
    }
    while (x <= -PI)
    {
        x = x + 2 * PI;
    }
    return x;
}

double real_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
        return z.a;
    else
        return z.a * cos(z.b);
}

double imag_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
        return z.b;
    else
        return z.a * sin(z.b);
}

double mag_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
        return sqrt(z.a * z.a + z.b * z.b);
    else
        return z.a;
}

double arg_part(struct complex_struct z)
{
    if (z.t == RECTANGULAR)
        if (z.a > 0)
            return atan(z.b / z.a);
        else if (z.a == 0 && z.b > 0)
            return PI / 2;
        else if (z.a == 0 && z.b < 0)
            return -PI / 2;
        else if (z.a < 0 && z.b >= 0)
            return atan(z.b / z.a) + PI;
        else if (z.a < 0 && z.b < 0)
            return atan(z.b / z.a) - PI;
        else
            return 0;
    else
        return z.b;
}

void print_complex(struct complex_struct z)
{
    if (imag_part(z) > 0)
        printf("%f+%fi\n", real_part(z), imag_part(z));
    else if(imag_part(z) < 0)
        printf("%f%fi\n", real_part(z), imag_part(z));
    else
        printf("%f\n", real_part(z));
}
struct complex_struct make_from_real_imag(double x, double y)
{
    struct complex_struct z;
    z.t = RECTANGULAR;
    z.a = x;
    z.b = y;
    return z;
}

struct complex_struct make_from_mag_arg(double x, double y)
{
    struct complex_struct z;
    z.t = POLAR;
    z.a = x;
    z.b = trans_to_arg(y);
    return z;
}

struct complex_struct complex_add(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_imag(real_part(z1) + real_part(z2), imag_part(z1) + imag_part(z2));
}

struct complex_struct complex_sub(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_real_imag(real_part(z1) - real_part(z2), imag_part(z1) - imag_part(z2));
}

struct complex_struct complex_mul(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_arg(mag_part(z1) * mag_part(z2), arg_part(z1) + arg_part(z2));
}

struct complex_struct complex_div(struct complex_struct z1, struct complex_struct z2)
{
    return make_from_mag_arg(mag_part(z1) / mag_part(z2), arg_part(z1) - arg_part(z2));
}

struct complex_struct segment_start(struct segment line)
{
    return line.start;
}

struct complex_struct segment_end(struct segment line)
{
    return line.end;
}

double complex_distance(struct complex_struct z1, struct complex_struct z2)
{
    return sqrt(pow(real_part(z1) - real_part(z2), 2) + pow(imag_part(z1) - imag_part(z2), 2));
}

double segment_len(struct segment line)
{
    return complex_distance(line.start, line.end);
}

struct segment make_from_complex(struct complex_struct start, struct complex_struct end)
{
    struct segment line;
    line.start = start;
    line.end = end;
    return line;
}

int main(void)
{
    struct complex_struct z1 = make_from_mag_arg(1, 9 * PI / 4);
    struct complex_struct z2 = make_from_real_imag(3.0, 4.0);
    struct complex_struct z3 = make_from_real_imag(5.0, 6.0);
    struct complex_struct z4 = make_from_mag_arg(1, 40);
    struct segment line1 = make_from_complex(z1, z2);
    print_complex(z1);
    print_complex(z2);
    print_complex(z3);
    print_complex(z4);
    print_complex(complex_add(z1, z2));
    print_complex(complex_sub(z1, z3));
    print_complex(complex_mul(z1, z2));
    print_complex(complex_div(z1, z3));
    printf("the length is %f.\n", segment_len(line1));
    return 0;
}
