#pragma once

#include <filesystem>

#include <glm/glm.hpp>

class Texture {
public:
    Texture(int32_t width, int32_t height);
    Texture(uint8_t* data, int32_t width, int32_t height);
    Texture(const std::filesystem::path& image);
    Texture(const Texture& other) = delete;
    ~Texture();

    inline int32_t GetWidth() const { return m_Width; }
    inline int32_t GetHeight() const { return m_Height; }
    inline int32_t GetBytesPerPixel() const { return m_BBP; }
    inline glm::vec2 GetSize() const { return { m_Width, m_Height }; }

    void Bind(uint32_t slot) const;

    void SetData(void* data);
private:
    uint32_t m_TextureID = 0;

    int32_t m_Width = 0, m_Height = 0, m_BBP = 0;
};