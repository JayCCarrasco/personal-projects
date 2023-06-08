const express = require('express');
const {theatre} = require('../data/books').infoBooks;

//router y middleware
const theatreRouter = express.Router();
theatreRouter.use(express.json());

theatreRouter.get(('/'), (req, res)=>{
    res.send(theatre);
})

module.exports = theatreRouter;