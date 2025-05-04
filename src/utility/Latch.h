#ifndef LATCH_H
#define LATCH_H

class Latch {
    public:
        Latch();
        explicit operator bool() const;
        void setOn();
    private:
        bool isOn;
};

#endif //LATCH_H
