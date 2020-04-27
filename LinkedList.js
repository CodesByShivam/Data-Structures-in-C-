var LinkedListNode = require('./LinkedListNode');

class LinkedList{

    constructor(){
        this.head = null;
        this.tail = null;
    }

    append(value){
        const newNode = new LinkedListNode(value);
        
        if(!this.head){
            this.head = newNode;
            this.tail = newNode;

            return this;
        }

        this.tail.next = newNode;
        this.tail = newNode;

        return this;

    }

    prepend(value){
        const newNode = new LinkedListNode(value, this.head);
        this.head = newNode;

        if(!this.tail){
            this.tail = newNode;
        }

        return this;
    }

}

module.exports = LinkedList;