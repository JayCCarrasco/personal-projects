const express = require('express');
const novelRouter = express.Router();
const {getAllBooks, createBook} = require('../controllers/novels');

novelRouter.route('/').get(getAllBooks).post(createBook);

module.exports = novelRouter;






/*OLD CODE
//import express and novels
const express = require('express');
const {novel} = require('../data/books').infoBooks;

//create router
const novelRouter = express.Router();

//middleware
novelRouter.use(express.json());

//get and exports
novelRouter.get(('/'), (req, res) => {
    res.send(novel);
})

//Filtering by author method
novelRouter.get(('/:author'), (req, res) => {
    let author = req.params.author;   
    let novelsFilter = novel.filter(novel => novel.author === author);
    if (novelsFilter.length === 0) {
        return res.status(404).send(`Novels with author ${author} could not be found`);
    }
    res.send(JSON.stringify(novelsFilter));
})

//Post method
novelRouter.post(('/'), (req, res) => {
    let newBook = req.body;
    novel.push(newBook);
    res.send(JSON.stringify(novel));
})

//Put method
novelRouter.put(('/'), (req, res) => {
    let updateBook = req.body;
    let index = novel.findIndex(novel => updateBook.id === novel.id);
    if(index === -1){
        return res.status(404).send(`The course with index ${updateBook.id} could not be found`);
    }
    novel.splice(index, 1, updateBook);
    res.send(novel);
})

//delete method
novelRouter.delete(('/:id'), (req, res) => {
    let id = req.params.id
    let index = novel.findIndex(novel => novel.id == id)
    if(index === -1){
        return res.status(404).send(`The course with index ${id} could not be found`);
    }
    novel.splice(index,1);
    res.send(novel);
})

module.exports = novelRouter;
*/