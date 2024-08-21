#include "framework.h"

// �⺻������ 2���� ����(������ �ǹ�)�� �ٷ�� Ŭ�����̹Ƿ�
// x��, y�� 2���� �ۼ��ϸ� ��
// �� 2���� ���� �θ� Ŭ����(=����ü)�� Float2���� �ٷ�� �ֿ��̹Ƿ�
// �θ� Ŭ������ �����ڸ� ���� �����ڷμ� �̿��ϸ� ��

Vector2::Vector2() : Float2(0, 0)
{
}

Vector2::Vector2(float x, float y) : Float2(x, y)
{
}

Vector2::Vector2(Float2 value) : Float2(value)
{
}

Vector2 Vector2::operator+(const Vector2& value) const
{
    return Vector2(x + value.x, y + value.y);
}

Vector2 Vector2::operator-(const Vector2& value) const
{
    return Vector2(x - value.x, y - value.y);
}

Vector2 Vector2::operator*(const Vector2& value) const
{
    return Vector2(x * value.x, y * value.y);
}

Vector2 Vector2::operator/(const Vector2& value) const
{
    return Vector2(x / value.x, y / value.y);
}

Vector2 Vector2::operator*(const float& value) const
{
    return Vector2(x * value, y * value);
}

Vector2 Vector2::operator/(const float& value) const
{
    return Vector2(x / value, y / value);
}

void Vector2::operator+=(const Vector2& value)
{
    x += value.x;
    y += value.y;
}

void Vector2::operator-=(const Vector2& value)
{
    x -= value.x;
    y -= value.y;
}

void Vector2::operator*=(const float& value)
{
    x *= value;
    y *= value;
}

void Vector2::operator/=(const float& value)
{
    x /= value;
    y /= value;
}

//���� ���� : ������ ũ��(=����)�� 1�� ����
// �⺻������ �����󿡼� ��ǥ�� ������ ���� �ڷ�μ� ǥ���� ����
// "����"���� X��, Y�� �������� �󸶸�ŭ �������ִ� �ڸ��� �ִ����� ǥ��(=������ ����)
// �� ���ʹ� �⺻������ ���� ������ ����Ű�� �ִ� �ϴ��� �� ������ ���̿� ���� ��ǥ���� �޶��� �� ������,
// �� ���̴� �ش� �������� �󸶳� ���� �ӵ��� ������ ���� �������� ����ϴ� �����̱⵵ ��

// �׸��� �׷� �������� �ʿ����� �ʰ� ������ �ش� ���Ͱ� ����Ű�� ������ ��� ���������� �ʿ��� ��찡 ����� ����
// ����, �ϳ��� ���Ͱ� �־����� �� �� ������ ���̶� ������� ����Ű�� ���⸸�� ���� �浵�� �ʿ�
// �� �� ���Ǵ� ���� �� ��������
// ��� ���ʹ� ���� ������ ����Ű�� ���� ���Ϳ� �Ǽ��� ���� �����μ� ǥ���� �����ϴ�,
// �ϴ� �� ������ ����Ű�� ���� ���͸� ���ϸ� ���� �̵��Ÿ� ���� �ű⿡ ������ ���� ���ؼ� ���ϴ� ��

// �����δ� �̹� �Ÿ� ���� �־��� ��Ȳ���� �������͸� ���� �� �̸� �̿��ؾ� �ϴ� ��찡 �� ����,
// �� ���� ���͸� ���ϰų� ���� ���ͷ� ����� �Լ����� �ٷ� ���� 2��

void Vector2::Normalize() // �� ���͸� ���� ���ͷ� ����� �Լ� = ���͸� ǥ��ȭ�ϴ� �Լ�
{
    float length = GetLength(); // ��� �ʿ� �̸� �����ص״�, ������ ���̸� ���ϴ� �Լ��� �̿�
    x /= length;
    y /= length;

    // ������ �̾߱��ߵ�, ���� ���ʹ� ���̰� 1�� ����
    // �׸��� ���� ���Ͱ� �ƴ� ���ʹ� ���� ���Ϳ� Ư�� ��(=������ ũ��)�� ���� ������ ǥ���� �� ����
    // �׷��� �� Ư�� ���� x��ǥ�� y��ǥ �������� ������ ������ ���� ���͸� ���� �� �ִ�
    // �� �Լ��� �׷��� ���� ���͸� ���ϴ� ���ÿ� �� ���� ��ü�� ���� ���ͷ� ����� ��
}
// �׷��� �����δ� ���� ��ü�� ǥ��ȭ���Ѿ� �� ���� ���� �ʰ�,
// Ư�� ���Ͱ� ��� ������ ����Ű���� �� ���� ���͸� ���ϱ⸸ �ϴ� ���� �� ����

Vector2 Vector2::Normalized() const // �� ������ ���� ���͸� ���ϴ� �Լ�
// ���ϱ⸸ �ϴ� ���̹Ƿ� const�� ���������μ� �� ���Ͱ� ���� ������ ��ü�� ������ �� ���� ������ ��
{
    float length = GetLength();
	return Vector2(x / length, y / length);
    // ���� �Ȱ��� ������� ǥ��ȭ�ϵ�, �� �� ��ü�� �� ������ �����ͷμ� ���������� �ʰ� ��ȯ���� ���
}

float Vector2::Angle() const // �� ������ ������ ���ϴ� �Լ�
{
	return atan2(y, x);
    // x,y�������� ��� ������ ���ϴ����� �ﰢ�Լ��� arctan2(y,x) ���� ã�ƺ��� ���� ����
}

Vector2 Vector2::TransformCoord(const Vector2& vec, const Matrix& mt)
// ���Ϳ� ����� ���� �� ����ϴ� �Լ�
{
    XMVECTOR temp = XMLoadFloat2(&vec);
    temp = XMVector2TransformCoord(temp, mt);

    Vector2 temp_pos;
    XMStoreFloat2(&temp_pos, temp);

    return temp_pos;
    // �̷� �Լ����� �̿��ؼ� DX���� ���Ϳ� ����� ����� �����Ѵٰ� ����ϸ� ��
}
