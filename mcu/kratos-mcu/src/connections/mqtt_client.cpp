#include <set>
#include <string>
#include <stdio.h>

std::set<char> topics;

void topicSubscribe(char& topicName){
    topics.insert(topicName);
}

void topicUnSubscribe(const std::string& topicName){
    topics.erase(topicName);
}

void getAllTopics(){
    for(std::string t : topics){
        printf("topic: %s \n",t);
    }
}