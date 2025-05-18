

class QuestGiver {

public:
    void giveQuest() {
        greetPlayer();
        describeQuest();
        offerReward();
        leaveConversation();
    }
    virtual ~QuestGiver() = default;

protected:
    virtual void greetPlayer() = 0;
    virtual void describeQuest() = 0;
    virtual void offerReward() = 0;
    virtual void leaveConversation() = 0;
};

class FisherQuest : public QuestGiver {
protected:
    void greetPlayer() override;
    void describeQuest() override;
    void offerReward() override;
    void leaveConversation() override;
};
class FarmerQuest : public QuestGiver {
protected:
    void greetPlayer() override;
    void describeQuest() override;
    void offerReward() override;
    void leaveConversation() override;
};