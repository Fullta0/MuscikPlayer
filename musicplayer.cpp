#include "musicplayer.h"
#include <iostream>

MusicPlayer::MusicPlayer()
: currenState(new StoppedState()){

}

MusicPlayer::~MusicPlayer() {
    delete currenState;
}

int MusicPlayer::Play() {
    currenState->Play(this);
    return 0;
}

int MusicPlayer::Pause() {
    currenState->Pause(this);
    return 0;
}

int MusicPlayer::Selecting() {
    currenState->Selecting(this);
    return 0;
}

int MusicPlayer::Stop() {
    currenState->Stop(this);
    return 0;
}

void MusicPlayer::SetState(State state)
{
    cout << "changing from " << currenState->GetName() << " to ";
    delete currenState;

    if(state == stopped)
    {
        currenState = new StoppedState();
    }
    else if(state == plaing)
    {
        currenState = new PlayingState();
    }
    else if(state == selecting)
    {
        currenState = new SelectingState();
    }
    else
    {
        currenState = new PausedState();
    }

    cout << currenState->GetName() << " state"<<endl;
}


MusicPlayerState::MusicPlayerState(std::string name)
: m_name(name) {

}

MusicPlayerState::~MusicPlayerState() {
}

void MusicPlayerState::Play(MusicPlayer *)
{
    cout << "Illegal state transition from " << GetName() << " to Playing"<<endl;
}

void MusicPlayerState::Pause(MusicPlayer *)
{
    cout << "Illegal state transition from " << GetName() << " to Paused"<<endl;
}

void MusicPlayerState::Selecting(MusicPlayer *)
{
    cout << "Illegal state transition from " << GetName() << " to Stopped"<<endl;
}

void MusicPlayerState::Stop(MusicPlayer *)
{
    cout << "Illegal state transition from " << GetName() << " to Stopped"<<endl;
}

PlayingState::PlayingState()
: MusicPlayerState(std::string("Playing")) {
}

PlayingState::~PlayingState() {
}

void PlayingState::Pause(MusicPlayer * player)
{
    player->SetState(MusicPlayer::paused);
}

void PlayingState::Selecting(MusicPlayer * player)
{
    player->SetState(MusicPlayer::selecting);
}

void PlayingState::Stop(MusicPlayer * player)
{
    player->SetState(MusicPlayer::stopped);
}

PausedState::PausedState()
: MusicPlayerState(std::string("Paused")) {
}

PausedState::~PausedState() {
}

void PausedState::Play(MusicPlayer * player)
{
    player->SetState(MusicPlayer::plaing);
}

void PausedState::Selecting(MusicPlayer * player)
{
    player->SetState(MusicPlayer::selecting);
}

void PausedState::Stop(MusicPlayer * player)
{
    player->SetState(MusicPlayer::stopped);
}

SelectingState::SelectingState()
: MusicPlayerState(std::string("Selecting")) {
}

SelectingState::~SelectingState() {
}

void SelectingState::Play(MusicPlayer * player)
{
    player->SetState(MusicPlayer::plaing);
}

StoppedState::StoppedState()
: MusicPlayerState(std::string("Stopped")) {
}

StoppedState::~StoppedState() {
}

void StoppedState::Play(MusicPlayer * player)
{
    player->SetState(MusicPlayer::plaing);
}



