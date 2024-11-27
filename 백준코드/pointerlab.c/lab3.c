#include <stdio.h>
#include <math.h>

// RGB 컬러를 표현하는 구조체
typedef struct {
    unsigned char red;    // 0-255
    unsigned char green;  // 0-255
    unsigned char blue;   // 0-255
} RGBColor;

// RGB를 16진수 문자열로 변환
void rgb_to_hex(RGBColor color, char* hex_out) {
    sprintf(hex_out, "#%02X%02X%02X", color.red, color.green, color.blue);
}

// 색상 출력(콘솔)
void print_color_info(RGBColor color, const char* label) {
    char hex[8];
    rgb_to_hex(color, hex);
    printf("%s: RGB(%d, %d, %d) / %s\n", label, color.red, color.green, color.blue, hex);
}

// RGB 색상 혼합
RGBColor mix_colors(RGBColor color1, RGBColor color2, float ratio) {
    RGBColor mixed;
    ratio = ratio > 1.0f ? 1.0f : ratio < 0.0f ? 0.0f : ratio;
    float inv_ratio = 1.0f - ratio;

    mixed.red = (unsigned char)(color1.red * ratio + color2.red * inv_ratio);
    mixed.green = (unsigned char)(color1.green * ratio + color2.green * inv_ratio);
    mixed.blue = (unsigned char)(color1.blue * ratio + color2.blue * inv_ratio);

    return mixed;
}

// 색상의 밝기 조절
RGBColor adjust_brightness(RGBColor color, float factor) {
    RGBColor adjusted;
    factor = factor < 0.0f ? 0.0f : factor;
    adjusted.red = (unsigned char)fmin(255, color.red * factor);
    adjusted.green = (unsigned char)fmin(255, color.green * factor);
    adjusted.blue = (unsigned char)fmin(255, color.blue * factor);

    return adjusted;
}

// 보색 생성
RGBColor get_complementary(RGBColor color) {
    RGBColor comp;
    comp.red = 255 - color.red;
    comp.green = 255 - color.green;
    comp.blue = 255 - color.blue;

    return comp;
}

int main() {
    
    RGBColor color2 = {0, 0, 0};
    RGBColor color1 = {0, 0, 0};

    printf("=== 사용자 입력 RGB 색상 혼합 프로그램 ===\n\n");

    // 첫 번째 색상 입력
    printf("첫 번째 색상 (R, G, B) 값을 입력하세요 (0~255): ");
    scanf("%hhu %hhu %hhu", &color1.red, &color1.green, &color1.blue);

    
    while (getchar() != '\n');

    // 두 번째 색상 입력
    printf("두 번째 색상 (R, G, B) 값을 입력하세요 (0~255): ");
    scanf("%hhu %hhu %hhu", &color2.red, &color2.green, &color2.blue);

    // 첫 번째 색상 출력
    print_color_info(color1, "첫 번째 색상");
    print_color_info(color2, "두 번째 색상");

    // 색상 혼합
    RGBColor mixed_color = mix_colors(color1, color2, 0.5f);
    print_color_info(mixed_color, "색상 혼합 결과");

    // 밝기 조절
    RGBColor bright_mixed = adjust_brightness(mixed_color, 1.5f);
    RGBColor dark_mixed = adjust_brightness(mixed_color, 0.5f);
    print_color_info(bright_mixed, "밝은 혼합색");
    print_color_info(dark_mixed, "어두운 혼합색");

    // 혼합색의 보색
    RGBColor comp_mixed = get_complementary(mixed_color);
    print_color_info(comp_mixed, "혼합색의 보색");

    return 0;
}



