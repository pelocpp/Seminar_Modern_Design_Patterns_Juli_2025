// ===========================================================================
// ConceptualExample.cpp // Proxy Pattern
// ===========================================================================

#include <memory>
#include <print>

/**
 * The SubjectBase interface declares common operations for both 'RealSubject'
 *    and the 'Proxy'. As long as the client works with 'RealSubject'
 *    using this interface, you'll be able to pass it a proxy
 *    instead of a real subject.
 */
class SubjectBase 
{
public:
    virtual void request() const = 0;
};

/**
 * The RealSubject contains some core business logic. Usually, RealSubjects are
 * capable of doing some useful work which may also be very slow or sensitive -
 * e.g. correcting input data. A Proxy can solve these issues without any
 * changes to the RealSubject's code.
 */
class RealSubject : public SubjectBase
{
public:
    void request() const override {
        std::println("RealSubject: Handling request.");
    }
};

/**
 * The Proxy has an interface identical to the RealSubject.
 */
class Proxy : public SubjectBase
{
private:
    std::unique_ptr<RealSubject> m_realSubject;

    bool checkAccess() const {
        // some real checks should go here.
        std::println("Proxy: Checking access prior to executing a real request."); 
        return true;   // false
    }

    void logAccess() const {
        std::println("Proxy: Logging the time of request.");
    }

    void logFailure() const {
        std::println("Proxy: Wrong Access Rights.");
    }

    /**
     * The Proxy maintains a reference to an object of the RealSubject class. It
     * can be either lazy-loaded or passed to the Proxy by the client.
     */
public:
    Proxy(std::unique_ptr<RealSubject> realSubject)
        : m_realSubject{ std::move(realSubject) }
    {}

    /**
     * The most common applications of the Proxy pattern are lazy loading,
     * caching, controlling the access, logging, etc. A Proxy can perform one of
     * these things and then, depending on the result, pass the execution to the
     * same method in a linked RealSubject object.
     */
    void request() const override {
        if (checkAccess()) {                // false  // Failure
            m_realSubject->request();
            logAccess();
        }
        else {
            logFailure();
        }
    }
};

/**
 * The client code is supposed to work with all objects (both subjects and
 * proxies) via the SubjectBase interface in order to support both real subjects and
 * proxies. In real life, however, clients mostly work with their real subjects
 * directly. In this case, to implement the pattern more easily, you can extend
 * your proxy from the real subject's class.
 */
static void clientCode(std::unique_ptr<SubjectBase> subject) {

    subject->request();
}

void test_conceptual_example()
{
    std::println("Client: Executing the client code with a real subject:");
    
    std::unique_ptr<RealSubject> realSubject{
        std::make_unique<RealSubject>() 
    };

    clientCode(std::move(realSubject));
    std::println();

    std::println("Client: Executing the same client code with a proxy:");
    
    std::unique_ptr<RealSubject> secondRealSubject{
        std::make_unique<RealSubject>()
    }; 
    
    std::unique_ptr<Proxy> proxy{
        std::make_unique<Proxy>(std::move(secondRealSubject))
    };

    clientCode(std::move(proxy));
}

// ===========================================================================
// End-of-File
// ===========================================================================
