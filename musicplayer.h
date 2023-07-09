#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H
#include <string>
using namespace std;

class MusicPlayerState;

class MusicPlayer
{
public:
    enum State
    {
        stopped,
        plaing,
        selecting,
        paused
    };

    MusicPlayer();
    virtual ~MusicPlayer();

    int Play();
    int Pause();
    int Selecting();
    int Stop();

    void SetState(State state);

private:
    MusicPlayerState *currenState;
};

class MusicPlayerState {
public:
    MusicPlayerState(string name);
    virtual ~MusicPlayerState();

    virtual void Play(MusicPlayer * player);
    virtual void Pause(MusicPlayer * player);
    virtual void Selecting(MusicPlayer * player);
    virtual void Stop(MusicPlayer * player);

    string GetName() { return m_name; }

private:
    string   m_name;
};

class PlayingState : public MusicPlayerState {
public:
    PlayingState();
    virtual ~PlayingState();

    virtual void Pause(MusicPlayer * player);
    virtual void Selecting(MusicPlayer * player);
    virtual void Stop(MusicPlayer * player);
};

class PausedState : public MusicPlayerState {
public:
    PausedState();
    virtual ~PausedState();

    virtual void Play(MusicPlayer * player);
    virtual void Selecting(MusicPlayer * player);
    virtual void Stop(MusicPlayer * player);
};

class SelectingState : public MusicPlayerState {
public:
    SelectingState();
    virtual ~SelectingState();

    virtual void Play(MusicPlayer * player);
};

class StoppedState : public MusicPlayerState {
public:
    StoppedState();
    virtual ~StoppedState();

    virtual void Play(MusicPlayer * player);
};



#endif // MUSICPLAYER_H
