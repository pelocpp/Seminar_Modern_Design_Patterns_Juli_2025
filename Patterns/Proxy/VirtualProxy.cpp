// ===========================================================================
// VirtualProxy.cpp // Proxy Pattern
// ===========================================================================

#include <memory>
#include <print>
#include <string>

struct Image {
    virtual void draw() = 0;
};

class EagerBitmap : public Image
{
private:
    std::string m_filename;

public:
    EagerBitmap(const std::string& filename) 
        : m_filename{ filename } 
    {
        std::println("loading image from {}", m_filename);
        // steps to load the image ...
    }

    void draw() { 
        std::println("drawing image {}", m_filename);
    }
};

class LazyBitmap : public Image    // Thumb Nail  //  very small tiny representation
{
private:
    std::unique_ptr<EagerBitmap>   m_bmp{ nullptr };
    std::string                    m_filename;

public:
    LazyBitmap(const std::string& filename)    // Thumb Nail  //  very small tiny representation
        : m_filename{ filename }
    {}

    void draw() {
        if (! m_bmp) {
            m_bmp = std::make_unique<EagerBitmap>(m_filename);
        }

        m_bmp->draw();
    }
};

static void test_virtual_proxy_eager()
{
    EagerBitmap img_1{ "image_1.png" };
    EagerBitmap img_2{ "image_2.png" };

    int choice = rand() % 2;
    (choice) ? img_1.draw() : img_2.draw();
}

static void test_virtual_proxy_lazy()
{
    LazyBitmap img_1{ "image_1.png" };
    LazyBitmap img_2{ "image_2.png" };

    int choice = rand() % 2;
    (choice) ? img_1.draw() : img_2.draw();
}

void test_virtual_proxy()
{
    test_virtual_proxy_eager();
    test_virtual_proxy_lazy();
}

// ===========================================================================
// End-of-File
// ===========================================================================
