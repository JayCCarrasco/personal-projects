const express = require('express');
const {theatre} = require('../data/books').infoBooks;

//router y middleware
const theatreRouter = express.Router();
theatreRouter.use(express.json());

theatreRouter.get(('/'), (req, res)=>{
    res.send(theatre);
})

theatreRouter.get(('/:author'), (req, res) => {
    let author = req.params.author;
    let theatreFilter = theatre.filter(book => book.author === author);
    if (theatreFilter.length === 0){
        return res.status(404).send(`There are no authors with name: ${author}`);
    }
    res.send(JSON.stringify(theatreFilter));
})

theatreRouter.post(('/'), (req, res) => {
    let bookPost = req.body;
    theatre.push(bookPost);
    res.send(JSON.stringify(theatre));
})

//put method
theatreRouter.put(('/'), (req, res) => {
    let bookChange = req.body;
    let indexChange = theatre.findIndex(book => book.id === bookChange.id)
    if (indexChange === -1){
        return res.status(404).send(`The id ${bookChange.id} does not exist`);
    }
    theatre.splice(indexChange, 1, bookChange);
    res.send(JSON.stringify(theatre));
})

theatreRouter.delete(('/:id'), (req, res) => {
    let bookDeleteID = req.params.id;
    let index = theatre.findIndex(book => book.id == bookDeleteID);
    console.log(index)
    if (index === -1){
        return res.status(404).send(`No ID: ${bookDeleteID}`);
    }
    theatre.splice(index,1);
    res.send(JSON.stringify(theatre));

})

module.exports = theatreRouter;