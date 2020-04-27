var LinkedList = require('./LinkedList');

var ll = new LinkedList();

var flag = 1;
while(flag){
    console.log('Linked List Operations : \n 1. Print \n 2. Append \n 3. Prepend \n 4. Exit');
    switch(prompt()){
        case 1: console.log('case 1');
        case 4: flag = 0;
    }
}

