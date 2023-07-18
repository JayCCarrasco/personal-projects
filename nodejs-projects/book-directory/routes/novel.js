const express = require('express');
const novelRouter = express.Router();
const theatreRouter = express.Router();
const {getAllBooks, createBook, getBook, modBook, delBook} = require('../controllers/novels');

novelRouter.route('/').get(getAllBooks).post(createBook);
novelRouter.route('/:author').get(getBook)
novelRouter.route('/:title').patch(modBook).delete(delBook);

module.exports = novelRouter;

