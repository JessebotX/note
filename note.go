package main

import (
	"regexp"
	"strings"
	"time"
)

type Note struct {
	FileName   string
	Title      string   `yaml:"title"`
	Date       string   `yaml:"date"`
	Tags       []string `yaml:"tags"`
	Identifier string   `yaml:"identifier"`
}

var ExcludedPunctuationRegexp string = "[][{}!@#$%^&*()=+'\"?,.|;:~`‘’“”/]*"

func NewNote(title string, tags []string) *Note {
	currentTime := time.Now()
	identifier := currentTime.Format("20060102T150405")
	dateString := currentTime.Format("2006-01-02T15:04:05-07:00")
	fileName := getNoteFileName(title, tags, currentTime)

	return &Note{
		FileName: fileName,
		Title: title,
		Date: dateString,
		Tags: tags,
		Identifier: identifier,
	}
}

func getNoteFileName(title string, tags []string, date time.Time) string {
	dateIdentifier := date.Format("20060102T150405")
	noteFileNameTitle := dateIdentifier + "--" + sanitizeForFileName(title) + getTagsForFileName(tags) + ".md"

	return noteFileNameTitle
}

func getTagsForFileName(tags []string) string {
	if len(tags) == 0 {
		return ""
	}

	result := "__"
	for i, tag := range tags {
		result += sanitizeForFileName(tag)

		if i < len(tags) - 1 {
			result += "_"
		}
	}

	return result
}

func sanitizeForFileName(str string) string {
	regex := regexp.MustCompile(ExcludedPunctuationRegexp)

	trimmed := strings.Trim(str, " ")
	removedIllegalCharacters := regex.ReplaceAllString(trimmed, "")
	replacedSpaces := strings.ReplaceAll(removedIllegalCharacters, " ", "-")
	result := strings.ToLower(replacedSpaces)
	return result
}
