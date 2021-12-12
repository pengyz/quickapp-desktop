#pragma once

class Framework {
private:
    Framework();
public:
    static Framework* get();
    bool init();

private:
    static Framework* m_framework;
    const char* glsl_version;
};