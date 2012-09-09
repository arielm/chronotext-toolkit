#pragma once

class Message;

#include <boost/thread/mutex.hpp>

#include <queue>

class MessageQueue
{
    std::queue<Message> queue;
    boost::mutex queueMutex;
    
public:
    Message nextMessage();
    bool enqueueMessage(const Message &message);
};
