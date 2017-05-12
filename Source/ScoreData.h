#pragma once
#include <vector>

using namespace std;

struct t_rect
{
    vector<float> pos;
    float w, h;
};


class Symbol
{
public:
    
private:
    t_rect m_rect;
};


class Stave
{
public:
    void addSymbol(Symbol& symbol)
    {
        m_symbol.emplace_back(symbol);
    }
    
private:
    vector<Symbol> m_symbol;
    t_rect m_rect;
};


class System
{
    System(){};
    System( t_rect rect )
    {
        m_rect = rect;
    };
    
public:
    void addStave(Stave& stave)
    {
        m_stave.emplace_back(stave);
    }

private:
    vector<Stave> m_stave;

    t_rect m_rect;
};


class Score
{
    Score(){};
    ~Score()
    {
        for ( int i = 0; i < m_system.size(); i++ )
        {
            delete m_system[i];
        }
    }
    
    
public:
    void addSystem(System *system)
    {
        m_system.emplace_back(system);
    }
    
    void getSystem();
    
private:
    vector<System*> m_system;
    
};